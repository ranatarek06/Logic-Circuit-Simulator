//#include "Input.h"
#include "Output.h"
#include <string>

Input::Input(window* pW)
{
	pWind = pW; //Point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	string userInput = "";
	char AsciiKey;


	while (true)
	{
		pWind->WaitKeyPress(AsciiKey);

		if (AsciiKey == 27)
		{
			pOut->ClearStatusBar();
			return string();
		}

		else if (AsciiKey == 13)
		{
			pOut->ClearStatusBar();
			return userInput;
		}

		else if (AsciiKey == 8)
		{
			if (!userInput.empty())
				userInput.pop_back();
		}

		else
		{
			userInput += AsciiKey;
			pOut->PrintMsg(userInput);
		}


		pOut->PrintMsg(userInput);
	}


	return string();
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//Application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
				break;
			case ITM_OR2: return ADD_OR_GATE_2;
				break;
			case ITM_EXIT: return EXIT;
				break;
			case ITM_NAND2: return ADD_NAND_GATE_2;
				break;
			case ITM_NOR2: return ADD_NOR_GATE_2;
				break;
			case ITM_AND3: return ADD_AND_GATE_3;
				break;
			case ITM_NOR3: return ADD_NOR_GATE_3;
				break;
			case ITM_XOR3: return ADD_XOR_GATE_3;
				break;
			case ITM_SWITCH: return ADD_SWITCH;
				break;
			case ITM_LED: return ADD_LED;
				break;
			case ITM_XOR2: return ADD_XOR_GATE_2;
				break;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
				break;
			case ITM_BUF: return ADD_BUF;
				break;
			case ITM_INV: return ADD_INV;
				break;
			case ITM_CNC: return ADD_CONNECTION;
				break;
			case ITM_COPY: return COPY;
				break;
			case ITM_CUT: return CUT;
				break;
			case ITM_PASTE: return PASTE;
				break;
			case ITM_SAVE: return SAVE;
				break;
			case ITM_MOVE: return MOVE;
				break;
			case ITM_DEL: return DEL;
				break;
			case ITM_MUL: return MUL;
				break;
			case ITM_SEL: return SEL;
				break;
			case ITM_UNSEL: return UNSEL;
				break;
			case ITM_LABEL: return LABEL;
				break;
			case ITM_EDITLABEL: return EDIT_LABEL;
				break;
			case ITM_LOAD: return LOAD;
				break;
			case ITM_REDO: return REDO;
				break;
			case ITM_UNDO: return UNDO;
				break;
				/*case ITM_STATUSBAR: return STATUS_BAR;
					break;
				case ITM_DSNTOOL:  return DSN_TOOL;*/
				// break; //
			case ITM_SIM_MODE:
				UI.AppMode = SIMULATION;
				return SIM_MODE;
				break;
			default: return DSN_MODE;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SEL;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_SIMC: return SIMC;
				break;
			case ITM_TTB: return TTB;
				break;
			case ITM_CPR: return CPR;
				break;
			case ITM_CVALID: return CVALID;
				break;
			case ITM_DSN_MODE:
				UI.AppMode = DESIGN;
				return DSN_MODE;
				break;
			case ITM_EXIT_S: return EXIT;
				break;
			default: return SIM_MODE;	//This should be changed after creating the compelete simulation bar 

			}
		}

		// Click in drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return SEL;  // Select a component

		// Click in status bar
		return STATUS_BAR;

	}
}


Input::~Input()
{
}
