#include "SimulationMode.h"
#include "ApplicationManager.h"
#include "Components/Switch.h"
#include "Components/LED.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

SimulationMode::SimulationMode(ApplicationManager* pApp)
{
    pManager = pApp;
}

// -------------------------------------------------------------
// 1. Circuit Validation
// -------------------------------------------------------------
bool SimulationMode::validateCircuit() const
{
    Output* pOut = pManager->GetOutput();

    int switches = 0;
    int leds = 0;

    for (int i = 0; i < pManager->GetCompCount(); i++)
    {
        Component* pComp = pManager->GetCompList()[i];

        if (dynamic_cast<SWITCH*>(pComp))
            switches++;
        else if (dynamic_cast<LED*>(pComp))
            leds++;

        if (pComp->GetInputPinCount() > 0 &&
            !pComp->AllInputPinsConnected())
        {
            pOut->PrintMsg("Invalid circuit: unconnected input pin.");
            return false;
        }
    }

    if (switches == 0 || leds == 0)
    {
        pOut->PrintMsg("Invalid circuit: need at least one Switch and one LED.");
        return false;
    }

    pOut->PrintMsg("Circuit is valid.");
    return true;
}

// -------------------------------------------------------------
// 2. Run One Simulation Step
// -------------------------------------------------------------
void SimulationMode::simulateCircuit()
{
    if (!validateCircuit())
        return;

    for (int i = 0; i < pManager->GetCompCount(); i++)
    {
        Component* pComp = pManager->GetCompList()[i];

        // Let component compute its outputs
        pComp->Operate();

        // Read computed output and propagate it (cast to STATUS in case component methods use int)
        STATUS out = static_cast<STATUS>(pComp->GetOutPinStatus());
        pComp->SetOutputPinStatus(out);
        pComp->Propagate(out);
    }

    pManager->UpdateInterface();
}

// -------------------------------------------------------------
// 3. Truth Table
// -------------------------------------------------------------
void SimulationMode::generateTruthTable()
{
    Output* pOut = pManager->GetOutput();
    vector<Component*> inputs;
    vector<Component*> outputs;

    for (int i = 0; i < pManager->GetCompCount(); i++)
    {
        Component* pComp = pManager->GetCompList()[i];

        if (dynamic_cast<SWITCH*>(pComp))
            inputs.push_back(pComp);
        else if (dynamic_cast<LED*>(pComp))
            outputs.push_back(pComp);
    }

    int inCount = static_cast<int>(inputs.size());
    int outCount = static_cast<int>(outputs.size());

    if (inCount == 0 || outCount == 0)
    {
        pOut->PrintMsg("Truth table needs switches and LEDs.");
        return;
    }

    // Limit inputs to prevent overflow on screen (max 5 switches = 32 rows)
    if (inCount > 5)
    {
        pOut->PrintMsg("Too many switches (max 5) for Truth Table visualisation.");
        return;
    }

    // Validate circuit
    if (!validateCircuit())
        return;

    unsigned int combinations = 1u << inCount;

    // Visualization Config
    int startX = UI.width - 250; 
    int startY = 100;
    int rowHeight = 20;
    string header = "Inputs | Outputs";
    
    // Clear area for table (simple white rectangle fill not available in Output, so we just draw over)
    pOut->PrintMsg("Generating Truth Table... Click/Press Key to dismiss.");
    
    // Draw Header
    pOut->DrawString(startX, startY, header);
    startY += rowHeight;
    pOut->DrawString(startX, startY, "----------------");
    startY += rowHeight;

    // Local simulation lambda
    auto runSimulationStep = [&]()
    {
        for (int i = 0; i < pManager->GetCompCount(); i++)
           pManager->GetCompList()[i]->Operate();
           
        for (int i = 0; i < pManager->GetCompCount(); i++)
        {
            STATUS out = static_cast<STATUS>(pManager->GetCompList()[i]->GetOutPinStatus());
            pManager->GetCompList()[i]->SetOutputPinStatus(out);
            pManager->GetCompList()[i]->Propagate(out);
        }
    };

    // Iterate combinations
    for (unsigned int comb = 0; comb < combinations; comb++)
    {
        string rowStr = "";
        
        // Set Inputs
        for (int j = 0; j < inCount; j++)
        {
            STATUS s = (comb & (1u << (inCount - 1 - j))) ? HIGH : LOW; // MSB first
            SWITCH* sw = dynamic_cast<SWITCH*>(inputs[j]);
            if (sw) sw->SetStatus(s);
            rowStr += (s == HIGH ? "1 " : "0 ");
        }

        rowStr += "| ";

        // Simulate
        runSimulationStep();

        // Read Outputs
        for (int k = 0; k < outCount; k++)
        {
            STATUS s = static_cast<STATUS>(outputs[k]->GetInputPinStatus(0));
            rowStr += (s == HIGH ? "1 " : "0 ");
        }

        pOut->DrawString(startX, startY + (comb * rowHeight), rowStr);
    }
    
    // Wait for user interaction to finish viewing
    pManager->GetInput()->GetPointClicked(startX, startY); // Wait for click
    pManager->UpdateInterface(); // Clear table
    pOut->PrintMsg("");
}

// -------------------------------------------------------------
// 4. Pin Probing
// -------------------------------------------------------------
STATUS SimulationMode::getPinStatus(int x, int y) const
{
    Output* pOut = pManager->GetOutput();
    Component* pComp = pManager->GetComponentAt(x, y);

    if (!pComp)
    {
        pOut->PrintMsg("Nothing here.");
        return LOW;
    }

    STATUS s = static_cast<STATUS>(pComp->GetOutputPinStatus());
    pOut->PrintMsg(s == HIGH ? "HIGH" : "LOW");
    return s;
}

