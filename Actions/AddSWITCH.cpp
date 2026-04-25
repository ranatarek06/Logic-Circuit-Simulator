#include "AddSWITCH.h"
#include "..\GUI\UI_Info.h"
#include "..\ApplicationManager.h"
#include "..\Components\SWITCH.h" // Ensure SWITCH class is declared

AddSWITCH::AddSWITCH(ApplicationManager* pApp) : Action(pApp)
{
	Cx = Cy = -1;
}

AddSWITCH::~AddSWITCH(void)
{
}

//Reads parameters required for action to execute
void AddSWITCH::ReadActionParameters()
{
	// Get input and output interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMsg("Adding a SWITCH: Click on the drawing area to place the switch");

	// Read center point
	pIn->GetPointClicked(Cx, Cy);

	// Calculate the rectangle corners from the center using UI sizes
	x1 = Cx - UI.SWITCH_Width / 2;
	y1 = Cy - UI.SWITCH_Height / 2;
	x2 = Cx + UI.SWITCH_Width / 2;
	y2 = Cy + UI.SWITCH_Height / 2;

	// Clear status bar
	pOut->ClearStatusBar();
}

void AddSWITCH::Execute()
{
	ReadActionParameters();

	// Validate click is inside drawing area (simple check)
	if (Cy < UI.ToolBarHeight || Cy > UI.height - UI.StatusBarHeight)
	{
		// Invalid placement
		pManager->GetOutput()->PrintMsg("Invalid location for switch. Action cancelled.");
		return;
	}

	GraphicsInfo GInfo = {};
	GInfo.x1 = x1;
	GInfo.y1 = y1;
	GInfo.x2 = x2;
	GInfo.y2 = y2;

	// Use the correct constructor: SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	const int SWITCH_FANOUT = 5; // Or use the correct default for your design
	SWITCH* pR = new SWITCH(GInfo, SWITCH_FANOUT);

	pManager->AddComponent(pR);
}

void AddSWITCH::Undo()
{
	// To be implemented: remove the last added switch or store action history
}

void AddSWITCH::Redo()
{
	// To be implemented
}