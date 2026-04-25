#include "AddORgate2.h"
#include "..\ApplicationManager.h"
#include "AddConnection.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
    // initialize center coordinates to a sentinel so they aren't left uninitialized
    Cx = Cy = -1;
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// Calculate half sizes of gate to ensure full gate fits in drawing area
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;
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

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the OR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	OR2* pA = new OR2(GInfo, OR2_FANOUT);
	pManager->AddComponent(pA);
}

void AddORgate2::Undo()
{
}

void AddORgate2::Redo()
{
}