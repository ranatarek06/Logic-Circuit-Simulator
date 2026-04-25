#include "Copy.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

Copy::Copy(ApplicationManager* pApp)
    : Action(pApp)
{
}

void Copy::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on component to copy");

    int x, y;
    pIn->GetPointClicked(x, y);

    Component* pComp = pManager->GetComponentAt(x, y);

    if (!pComp)
    {
        pOut->PrintMsg("No component selected");
        return;
    }


    pManager->SetClipboard(pComp->Clone());

    pOut->PrintMsg("Component copied");
}