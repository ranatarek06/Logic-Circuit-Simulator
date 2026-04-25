#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar(bool  select) const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	//TODO: Prepare image for each menu item and add it to the list
	string MenuItemImages[ITM_DSN_CNT];
	if (select == true) {

		MenuItemImages[ITM_AND2] = "images/Menu/Menu_AND2.jpg";
		MenuItemImages[ITM_NAND2] = "images/Menu/Menu_NAND2.jpg";
		MenuItemImages[ITM_OR2] = "images/Menu/Menu_OR2.jpg";
		MenuItemImages[ITM_NOR2] = "images/Menu/Menu_NOR2.jpg";
		MenuItemImages[ITM_XOR2] = "images/Menu/Menu_XOR2.jpg";
		MenuItemImages[ITM_XNOR2] = "images/Menu/Menu_XNOR2.jpg";
		MenuItemImages[ITM_BUF] = "images/Menu/Menu_BUF.jpg";
		MenuItemImages[ITM_INV] = "images/Menu/Menu_INV.jpg";
		MenuItemImages[ITM_AND3] = "images/Menu/Menu_AND3.jpg";
		MenuItemImages[ITM_NOR3] = "images/Menu/Menu_NOR3.jpg";
		MenuItemImages[ITM_XOR3] = "images/Menu/Menu_XOR3.jpg";
		MenuItemImages[ITM_SWITCH] = "images/Menu/Menu_SWITCH.jpg";
		MenuItemImages[ITM_LED] = "images/Menu/Menu_LED.jpg";
		MenuItemImages[ITM_CNC] = "images/Menu/Menu_CNC.jpg";
		MenuItemImages[ITM_COPY] = "images/Menu/Menu_COPY.jpg";
		MenuItemImages[ITM_CUT] = "images/Menu/Menu_CUT.jpg";
		MenuItemImages[ITM_PASTE] = "images/Menu/Menu_PASTE.jpg";
		MenuItemImages[ITM_SAVE] = "images/Menu/Menu_SAVE.jpg";
		MenuItemImages[ITM_MOVE] = "images/Menu/Menu_MOVE.jpg";
		MenuItemImages[ITM_DEL] = "images/Menu/Menu_DEL.jpg";
		MenuItemImages[ITM_MUL] = "images/Menu/Menu_MUL.jpg";
		MenuItemImages[ITM_SEL] = "images/Menu/Menu_SEL.jpg";
		MenuItemImages[ITM_UNSEL] = "images/Menu/Menu_UNSEL.jpg";
		MenuItemImages[ITM_LABEL] = "images/Menu/Menu_LABEL.jpg";
		MenuItemImages[ITM_EDITLABEL] = "images/Menu/Menu_EDITLABEL.jpg";
		MenuItemImages[ITM_LOAD] = "images/Menu/Menu_LOAD.jpg";
		MenuItemImages[ITM_REDO] = "images/Menu/Menu_REDO.jpg";
		MenuItemImages[ITM_UNDO] = "images/Menu/Menu_UNDO.jpg";
		MenuItemImages[ITM_SIM_MODE] = "images/Menu/Menu_SIMM.jpg";
		MenuItemImages[ITM_EXIT] = "images/Menu/Menu_EXIT.jpg";

		//Draw menu item one image at a time
		for (int i = 0; i < ITM_DSN_CNT - 1; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
	else {
		MenuItemImages[ITM_EMPTY_D] = "images/Menu/EMPTY.jpg";

		for (int i = 0; i < ITM_DSN_CNT - 1; i++)
			pWind->DrawImage(MenuItemImages[30], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		//insert white images makan el icons eli malhash sowar fel simulation tool bar


		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar(bool select) const
{

	UI.AppMode = SIMULATION;
	string MenuItemImages[ITM_SIM_CNT];	//Simulation Mode
	if (select == true) {
		MenuItemImages[ITM_SIMC] = "images/Menu/Menu_SIMC.jpg";
		MenuItemImages[ITM_TTB] = "images/Menu/Menu_TTB.jpg";
		MenuItemImages[ITM_CPR] = "images/Menu/Menu_COPY.jpg";
		MenuItemImages[ITM_CVALID] = "images/Menu/Menu_CVALID.jpg";
		MenuItemImages[ITM_DSN_MODE] = "images/Menu/Menu_DSNM.jpg";
		MenuItemImages[ITM_EXIT_S] = "images/Menu/Menu_EXIT_S.jpg";
		MenuItemImages[ITM_EMPTY_S] = "images/Menu/EMPTY.jpg";

		//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
		// Draw only the initialized buttons

		//int NumSimButtons = 6; // Number of actual buttons in simulation toolbar
		for (int i = 0; i < ITM_SIM_CNT; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

		for (int i = ITM_SIM_CNT; i < ITM_DSN_CNT; i++)
		{
			pWind->DrawImage(MenuItemImages[ITM_EMPTY_S], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}

		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images/Gates/Gate_AND2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_AND2_HB.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_NAND2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_NAND2_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_OR2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_OR2_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_NOR2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_NOR2_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_XOR2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_XOR2_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_XNOR2_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_XNOR2_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawBUF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_BUF_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_BUF_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_INV_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_INV_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_AND3_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_AND3_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_NOR3_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_NOR3_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "Images/Gates/Gate_XOR3_HR.jpg";
	else
		GateImage = "Images/Gates/Gate_XOR3_HB.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool ON, bool selected) const
{
	string GateImage;
	if (ON)
        GateImage = "Images/Gates/SWITCH_HR.jpg"; // Use Highlighted as ON representation for now
    else if (selected)
		GateImage = "Images/Gates/SWITCH_HR.jpg";
	else
		GateImage = "Images/Gates/SWITCH_HB.jpg";

	// Use SWITCH-specific UI dimensions so the displayed image matches component m_GfxInfo
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

// replace old DrawLED that used AND2 size
// replace old DrawLED that used AND2 size
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool ON, bool selected) const
{
	string GateImage;
	if (ON)
        GateImage = "Images/Gates/LED_HR.jpg"; // Use Highlighted Red for ON
    else if (selected)
		GateImage = "Images/Gates/LED_HR.jpg";
	else
		GateImage = "Images/Gates/LED_HB.jpg";

	// Use LED-specific dimensions so the displayed image matches m_GfxInfo
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	color wirecolour;
	if (selected)
		wirecolour = UI.SelectColor;
	else
		wirecolour = UI.ConnColor;
	pWind->SetPen(wirecolour, 3);
	int x1 = r_GfxInfo.x1, y1 = r_GfxInfo.y1, x2 = r_GfxInfo.x2, y2 = r_GfxInfo.y2;
	int xmid = (x1 + x2) / 2;
	if (y1 == y2) // for el horizontal line
	{
		pWind->DrawLine(x1, y1, x2, y2);
		return;
	}
	if (x1 == x2) // for el vertical line
	{
		pWind->DrawLine(x1, y1, x2, y2);
		return;
	}
	else // for el L shape line (broken)
	{
		pWind->DrawLine(x1, y1, xmid, y1);
		pWind->DrawLine(xmid, y1, xmid, y2);
		pWind->DrawLine(xmid, y2, x2, y2);
		return;
	}
}

void Output::DrawString(int x, int y, string label) const
{
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK, 1);
	pWind->DrawString(x, y, label);
}

Output::~Output()
{
	delete pWind;
}


