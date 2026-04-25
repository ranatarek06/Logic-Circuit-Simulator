#include "ActionSIMC.h"
#include "../ApplicationManager.h"
#include "../Components/SWITCH.h"

ActionSIMC::ActionSIMC(ApplicationManager* pApp) : Action(pApp), clickX(0), clickY(0)
{
}

void ActionSIMC::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on a switch to toggle");
    pIn->GetPointClicked(clickX, clickY);
}

void ActionSIMC::Execute()
{
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();
    int compCount = pManager->GetCompCount();
    bool found = false;

    for (int i = 0; i < compCount; i++)
    {
        Component* pComp = pManager->GetCompAt(i);
        if (!pComp) continue;

        SWITCH* sw = dynamic_cast<SWITCH*>(pComp);
        if (sw)
        {
            GraphicsInfo gfx = pComp->GetGraphicsInfo();
            if (clickX >= gfx.x1 && clickX <= gfx.x2 &&
                clickY >= gfx.y1 && clickY <= gfx.y2)
            {
                found = true;
                sw->Toggle();
                sw->Operate();
                pManager->UpdateInterface();

                string msg = "Switch: ";
                msg += (sw->GetOutPinStatus() == HIGH) ? "HIGH" : "LOW";
                pOut->PrintMsg(msg);
                break;
            }
        }
    }

    if (!found)
    {
        pOut->PrintMsg("No switch clicked");
    }
}