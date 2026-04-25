#include "AddBUFgate.h"
#include "..\ApplicationManager.h"

AddBUFgate::AddBUFgate(ApplicationManager* pApp) :Action(pApp)
{
	Cx = Cy = -1;
}

AddBUFgate::~AddBUFgate(void)
{
}

void AddBUFgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Input BUF Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// Calculate half sizes of gate to ensure full gate fits in drawing area
	int Len = UI.BUF_Width;
	int Wdth = UI.BUF_Height;
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

void AddBUFgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.BUF_Width;
	int Wdth = UI.BUF_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the BUF gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	BUF* pA = new BUF(GInfo, BUF_FANOUT);
	pManager->AddComponent(pA);
}

void AddBUFgate::Undo()
{
}

void AddBUFgate::Redo()
{
}