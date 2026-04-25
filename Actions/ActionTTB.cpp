#include "ActionTTB.h"
#include "../ApplicationManager.h"
#include "../SimulationMode.h"
#include "../Components/SWITCH.h"
#include "../Components/LED.h"

ActionTTB::ActionTTB(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionTTB::Execute()
{
	// Get access to the simulation mode via ApplicationManager
	if (pManager->GetSimulationMode())
	{
		pManager->GetSimulationMode()->generateTruthTable();
	}
	else
	{
		pManager->GetOutput()->PrintMsg("Error: Simulation Mode not active.");
	}
}