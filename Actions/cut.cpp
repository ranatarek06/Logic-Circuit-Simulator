#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Output.h" // Add this include to fix "Output" undefined
#include "..\GUI/Input.h"  // Add this include to ensure "Input" is defined

Cut::Cut(ApplicationManager* pApp) : Action(pApp) {}


void Cut::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on component to cut");

    int x, y;
    pIn->GetPointClicked(x, y);

    Component* Comp = pManager->GetComponentAt(x, y);

    if (!Comp)
    {
        pOut->PrintMsg("No component selected");
        return;
    }

    pManager->SetClipboard(Comp->Clone());


    pManager->DeleteComponent(Comp);

    pOut->PrintMsg("Component cut");
}