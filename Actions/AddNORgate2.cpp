#include "AddNORgate2.h"
#include "..\ApplicationManager.h"

AddNORgate2::AddNORgate2(ApplicationManager* pApp) :Action(pApp)
{
	Cx = Cy = -1;
}

AddNORgate2::~AddNORgate2(void)
{
}

void AddNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// Calculate half sizes of gate to ensure full gate fits in drawing area
	int Len = UI.NOR2_Width;
	int Wdth = UI.NOR2_Height;
	int halfLen = Len / 2;
	int halfWdth = Wdth / 2;

	// Check that the gate rectangle will be fully inside the drawing area:
	bool outsideLeftOrRight = (Cx - halfLen < 0) || (Cx + halfLen > UI.width);
	bool outsideTopOrBottom = (Cy - halfWdth < UI.ToolBarHeight) || (Cy + halfWdth > UI.height - UI.StatusBarHeight);

	if (outsideLeftOrRight || outsideTopOrBottom)
	{
		pOut->PrintMsg("Invalid position, click anywhere to continue");
		int dummyX, dummyY;
		// Wait for user acknowledgement click
		pIn->GetPointClicked(dummyX, dummyY);
		Cx = Cy = -1;
		return;
	}

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cx == -1 && Cy == -1)
		return;

	//Calculate the rectangle Corners
	int Len = UI.NOR2_Width;
	int Wdth = UI.NOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NOR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NOR2* pA = new NOR2(GInfo, NOR2_FANOUT);
	pManager->AddComponent(pA);
}

void AddNORgate2::Undo()
{
}

void AddNORgate2::Redo()
{
}