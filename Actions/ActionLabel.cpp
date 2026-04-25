#include "ActionLabel.h"
#include "..\ApplicationManager.h"

ActionLabel::ActionLabel(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionLabel::ReadActionParameters()
{
}

void ActionLabel::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Label: Click on a component to name it");
	int x, y;
	pIn->GetPointClicked(x, y);

	Component* pComp = pManager->GetComponentAt(x, y);
	if (pComp != NULL)
	{
		pOut->PrintMsg("Enter label name:");
		string label = pIn->GetSrting(pOut); // Assuming you fixed the typo in Input.h
		pComp->SetLabel(label);
		pOut->ClearStatusBar();
	}
}
void ActionLabel::Undo() {}
void ActionLabel::Redo() {}