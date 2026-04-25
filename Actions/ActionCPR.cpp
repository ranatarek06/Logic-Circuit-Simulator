#include "ActionCPR.h"
#include "../ApplicationManager.h"
#include "../Components/SWITCH.h"
#include "../Components/LED.h"

ActionCPR::ActionCPR(ApplicationManager* pApp)
    : Action(pApp), x(0), y(0), pComp(nullptr)
{
}

void ActionCPR::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on any component");
    pIn->GetPointClicked(x, y);
}

void ActionCPR::Execute()
{
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();
    int compCount = pManager->GetCompCount();

    pComp = nullptr;
    for (int i = 0; i < compCount; i++)
    {
        Component* comp = pManager->GetCompAt(i);
        if (comp)
        {
            GraphicsInfo gfx = comp->GetGraphicsInfo();
            if (x >= gfx.x1 && x <= gfx.x2 && y >= gfx.y1 && y <= gfx.y2)
            {
                pComp = comp;
                break;
            }
        }
    }

    if (!pComp)
    {
        pOut->PrintMsg("No component found");
        return;
    }

    string compType = "Component";
    if (dynamic_cast<SWITCH*>(pComp)) compType = "Switch";
    else if (dynamic_cast<LED*>(pComp)) compType = "LED";
    else compType = "Gate";

    int status = pComp->GetOutPinStatus();
    string message = compType + " = ";

    if (status == HIGH)
        message += "HIGH";
    else if (status == LOW)
        message += "LOW";
    else
        message += "Unknown";

    pOut->PrintMsg(message);
}