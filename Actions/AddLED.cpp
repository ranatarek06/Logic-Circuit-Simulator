#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp): Action(pApp)
{
	Cx = Cy = -1;
}

AddLED::~AddLED(void)
{
}

//Reads parameters required for action to execute
void AddLED::ReadActionParameters()
{
	// Get input and output interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMsg("Adding a LED: Click on the drawing area to place the led");

	// Read center point
	pIn->GetPointClicked(Cx, Cy);

	// Calculate the rectangle corners from the center using UI sizes
	x1 = Cx - UI.LED_Width / 2;
	y1 = Cy - UI.LED_Height / 2;
	x2 = Cx + UI.LED_Width / 2;
	y2 = Cy + UI.LED_Height / 2;

	// Clear status bar
	pOut->ClearStatusBar();
}

void AddLED::Execute()
{
	ReadActionParameters();

	// Validate click is inside drawing area (simple check)
	if (Cy < UI.ToolBarHeight || Cy > UI.height - UI.StatusBarHeight)
	{
		// Invalid placement
		pManager->GetOutput()->PrintMsg("Invalid location for led. Action cancelled.");
		return;
	}

	GraphicsInfo GInfo = {};
	GInfo.x1 = x1;
	GInfo.y1 = y1;
	GInfo.x2 = x2;
	GInfo.y2 = y2;

	// LED constructor signature expects a GraphicsInfo*; pass the address.
	LED* pR = new LED(GInfo, 1); // 1 is a default fan-out, adjust as needed
	pManager->AddComponent(pR);
}

void AddLED::Undo()
{
}

void AddLED::Redo()
{
}