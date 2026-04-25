#include "Paste.h"
#include "..\Components/Component.h"
#include "..\Components/connection.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Output.h" // Add this include to fix "Output" undefined
#include "..\GUI/Input.h"  // Add this include to ensure "Input" is defined

Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}

void Paste::ReadActionParameters() {}

void Paste::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    Component* Comp = pManager->GetClipboard();
    if (!Comp)
    {
        pOut->PrintMsg("Clipboard empty");
        return;
    }

    pOut->PrintMsg("Click to paste");

    int x, y;
    pIn->GetPointClicked(x, y);

    Component* NewComp = Comp->Clone();   // VERY IMPORTANT
    NewComp->SetLocation(x, y);

    pManager->AddComponent(NewComp);
    pOut->PrintMsg("Component pasted");
}
void Paste::Undo() {}
void Paste::Redo() {}