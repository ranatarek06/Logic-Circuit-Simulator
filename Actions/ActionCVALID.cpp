#include "ActionCVALID.h"
#include "../ApplicationManager.h"
#include "../Components/SWITCH.h"
#include "../Components/LED.h"

ActionCVALID::ActionCVALID(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionCVALID::Execute()
{
    Output* pOut = pManager->GetOutput();

    int compCount = pManager->GetCompCount();
    if (compCount == 0)
    {
        pOut->PrintMsg("Circuit is empty!");
        return;
    }

    int switchCount = 0;
    int ledCount = 0;
    bool hasErrors = false;
    string errorMsg = "";

    for (int i = 0; i < compCount; i++)
    {
        Component* pComp = pManager->GetCompAt(i);
        if (!pComp) continue;

        SWITCH* sw = dynamic_cast<SWITCH*>(pComp);
        if (sw)
        {
            switchCount++;
            if (pComp->GetOutPinStatus() == -1)
            {
                hasErrors = true;
                errorMsg += "Switch has no output\n";
            }
        }

        LED* led = dynamic_cast<LED*>(pComp);
        if (led)
        {
            ledCount++;
            if (pComp->GetInputPinStatus(1) == -1)
            {
                hasErrors = true;
                errorMsg += "LED has no input\n";
            }
        }
    }

    if (switchCount == 0)
    {
        errorMsg += "No switches in circuit\n";
        hasErrors = true;
    }

    if (ledCount == 0)
    {
        errorMsg += "No LEDs in circuit\n";
        hasErrors = true;
    }

    if (hasErrors)
    {
        pOut->PrintMsg("ERROR: " + errorMsg);
    }
    else
    {
        pOut->PrintMsg("Circuit is VALID");
    }
}