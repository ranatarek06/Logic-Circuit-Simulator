#include "ActionDelete.h"
#include "..\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionDelete::ReadActionParameters()
{
}

void ActionDelete::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Delete: Click on the component to delete");
	int x, y;
	pIn->GetPointClicked(x, y);

	Component* pComp = pManager->GetComponentAt(x, y);
	if (pComp != NULL)
	{
		pManager->DeleteComponent(pComp);
		pOut->PrintMsg("Component Deleted.");
	}
}
void ActionDelete::Undo() {}
void ActionDelete::Redo() {}