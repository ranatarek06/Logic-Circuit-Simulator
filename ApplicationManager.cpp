#include "ApplicationManager.h"
#include "Actions/AddANDgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddXORgate2.h"
#include "Actions/AddXNORgate2.h"
#include "Actions/AddANDgate3.h"
#include "Actions/AddNORgate3.h"
#include "Actions/AddXORgate3.h"
#include "Actions/AddBUFgate.h"
#include "Actions/AddINVgate.h"
#include "Actions/AddSWITCH.h"
#include "Actions/AddLED.h"
#include "SimulationMode.h"
#include "Actions/AddConnection.h"
#include "Actions/ActionCVALID.h"
#include "Actions/ActionSIMC.h"
#include "Actions/ActionTTB.h"
#include "Actions/ActionCPR.h"
#include "Actions/ActionEXIT.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionDelete.h"
#include "Actions/ActionLabel.h"
#include "Actions/ActionEdit.h"
#include "Actions/ActionMove.h"
#include "Actions/Copy.h"
#include "Actions/cut.h"
#include "Actions/paste.h"
#include "Actions/ActionSave.h"
#include "Actions/ActionLoad.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();

	pSimMode = new SimulationMode(this);

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////


void ApplicationManager::DeleteComponent(Component* pCompToDelete)
{
	if (!pCompToDelete) return;

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == pCompToDelete)
		{
			delete CompList[i]; // Free memory

			// Move the last component into this empty spot to keep array contiguous
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;
			return;
		}
	}
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;

	case ADD_BUF:
		pAct = new AddBUFgate(this);
		break;

	case ADD_INV:
		pAct = new AddINVgate(this);
		break;

	case ADD_SWITCH:
		pAct = new AddSWITCH(this);
		break;

	case ADD_LED:
		pAct = new AddLED(this);
		break;

	case SIM_MODE:
		UI.AppMode = SIMULATION;
		GetOutput()->CreateSimulationToolBar(true);
		UpdateInterface();
		break;

		case CVALID:
			pAct = new ActionCVALID(this); // Pass the raw pointer
			break;

		case SIMC:
			pAct = new ActionSIMC(this);   
			break;

		case TTB:
			pAct = new ActionTTB(this);    
			break;

		case CPR:
			pAct = new ActionCPR(this);
			break;

	case DSN_MODE:
		UI.AppMode = DESIGN;
		GetOutput()->CreateDesignToolBar(true);
		UpdateInterface();
		break;

	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		pAct = new AddConnection(this);
			break;

	case SEL:
		pAct = new ActionSelect(this);
		break;

	case DEL:
		pAct = new ActionDelete(this);
		break;

	case LABEL:
		pAct = new ActionLabel(this);
		break;

	case EDIT_LABEL:
		pAct = new ActionEdit(this);
		break;
		// ----------------------------

	case MOVE:
		pAct = new ActionMove(this);
		break;

	case COPY:
		pAct = new Copy(this);
		break;

	case CUT:
		pAct = new Cut(this);
		break;

	case PASTE:
		pAct = new Paste(this);
		break;


	case SAVE:
		pAct = new ActionSave(this);
		break;

	case LOAD:
		pAct = new ActionLoad(this);
		break;


	case EXIT:
		///TODO: create ExitAction here
		pAct = new ActionEXIT(this);
		break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	if (UI.AppMode == DESIGN)
		OutputInterface->CreateDesignToolBar(true);
	else
		OutputInterface->CreateSimulationToolBar(true);

	OutputInterface->ClearDrawingArea();

	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetCompAt(int index) const
{
	if (index < 0 || index >= CompCount)
		return nullptr;
	return CompList[index];
}

Component* ApplicationManager::GetClipboard()
{
	return Clipboard;
}

Component* ApplicationManager::GetComponentAt(int x, int y) const
{
	// Search from topmost component to bottommost so we pick the visible component
	for (int i = CompCount - 1; i >= 0; --i)
	{
		Component* comp = CompList[i];
		if (!comp) continue;

		GraphicsInfo gfx = comp->GetGraphicsInfo();

		// Extract rectangle corners.
		// Most student projects use gfx.PointsList[0].x/y and gfx.PointsList[1].x/y
		int x1 = gfx.x1;
		int y1 = gfx.y1;
		int x2 = gfx.x2;
		int y2 = gfx.y2;

		int left   = (x1 < x2) ? x1 : x2;
		int right  = (x1 > x2) ? x1 : x2;
		int top    = (y1 < y2) ? y1 : y2;
		int bottom = (y1 > y2) ? y1 : y2;

		if (x >= left && x <= right && y >= top && y <= bottom)
			return comp;
	}

	// No component found at the given coordinates
	return nullptr;
}


GraphicsInfo ApplicationManager::GetComponentGraphics(int index) const
{
	if (index >= 0 && index < CompCount && CompList[index])
	{
		return CompList[index]->GetGraphicsInfo();
	}

	GraphicsInfo nullGfx = { 0, 0, 0, 0 };
	return nullGfx;
}
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete pSimMode;
	delete OutputInterface;
	delete InputInterface;

}

void ApplicationManager::SetClipboard(Component* Comp)
{
	if (Clipboard)
		delete Clipboard;
	Clipboard = Comp;
}

void ApplicationManager::ClearAll()
{
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
}

void ApplicationManager::SaveAll(ofstream& OutFile)
{
	OutFile << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Save(OutFile);
	OutFile << "END" << endl;
}

SimulationMode* ApplicationManager::GetSimulationMode() const
{
	return pSimMode;
}
