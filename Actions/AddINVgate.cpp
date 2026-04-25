#include "AddINVgate.h"
#include "..\ApplicationManager.h"

AddINVgate::AddINVgate(ApplicationManager* pApp) :Action(pApp)
{
	Cx = Cy = -1;
}

AddINVgate::~AddINVgate(void)
{
}

void AddINVgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Input INV Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// Calculate half sizes of gate to ensure full gate fits in drawing area
	int Len = UI.INV_Width;
	int Wdth = UI.INV_Height;
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

void AddINVgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cx == -1 && Cy == -1)
		return;

	//Calculate the rectangle Corners
	int Len = UI.INV_Width;
	int Wdth = UI.INV_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the INV gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INV* pA = new INV(GInfo, INV_FANOUT);
	pManager->AddComponent(pA);
}

void AddINVgate::Undo()
{
}

void AddINVgate::Redo()
{
}