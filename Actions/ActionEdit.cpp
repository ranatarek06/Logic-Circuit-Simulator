#include "ActionEdit.h"
#include "..\ApplicationManager.h"

ActionEdit::ActionEdit(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionEdit::ReadActionParameters()
{
}

void ActionEdit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Edit: Click on a component to edit label");
	int x, y;
	pIn->GetPointClicked(x, y);

	Component* pComp = pManager->GetComponentAt(x, y);
	if (pComp != NULL)
	{
		pOut->PrintMsg("Old Label: " + pComp->GetLabel() + " | Enter new label:");
		string label = pIn->GetSrting(pOut);
		pComp->SetLabel(label);
		pOut->ClearStatusBar();
	}
}
void ActionEdit::Undo() {}
void ActionEdit::Redo() {}