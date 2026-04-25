#include "ActionSelect.h"
#include "..\ApplicationManager.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionSelect::ReadActionParameters()
{
}

void ActionSelect::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMsg("Select: Click on a component to select/unselect");
	int x, y;
	pIn->GetPointClicked(x, y);

	Component* pComp = pManager->GetComponentAt(x, y);
	if (pComp != NULL)
	{
		if (pComp->IsSelected())
			pComp->SetSelected(false);
		else
			pComp->SetSelected(true);
	}
	pOut->ClearStatusBar();
}
void ActionSelect::Undo() {}
void ActionSelect::Redo() {}