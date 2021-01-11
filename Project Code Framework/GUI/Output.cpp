#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = DARKBLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	CreateSimulationToolBar();  //Create Simulation bar

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
	pWind->SetPen(GREY, 3);
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
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.ToolItemWidth + 10, UI.ToolBarHeight + 30, UI.width, UI.height - UI.StatusBarHeight - 5);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.
	/* ITM_NOR2,
	ITM_XOR2,
	ITM_XNOR2,
	ITM_AND3,
	ITM_NOR3,
	ITM_XOR3,
	ITM_BUFFER,
	ITM_INVERTER,
	ITM_SWITCH, */
	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Gate\\Gate_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Gate\\Gate_OR2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Gate\\Gate_NOR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Gate\\Gate_NAND2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Gate\\Gate_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Gate\\Gate_XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Gate\\Gate_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Gate\\Gate_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Gate\\Gate_XOR3.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Gate\\Gate_BUFFER.jpg";
	MenuItemImages[ITM_INVERTER] = "images\\Gate\\Gate_INVERTER.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Gate\\SWITCH.jpg";
	MenuItemImages[ITM_LED] = "images\\Gate\\LED.jpg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\Menu_Wire.jpg";

	//MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	pWind->SetPen(WHITE);
	int tempx = 10;
	//int tempy = UI.ToolBarHeight+30;
	for (int i = 0; i < ITM_DSN_CNT; i++)
	{
		if (tempx + UI.ToolItemWidth < UI.width)
		{
			pWind->DrawImage(MenuItemImages[i], tempx, 10, UI.ToolItemWidth, UI.ToolBarHeight);
			tempx += UI.ToolItemWidth;
			pWind->DrawRectangle(tempx, 10, tempx + 11, UI.ToolBarHeight, FILLED);
			tempx += 11;

		}
		/*else
		{
			pWind->DrawImage(MenuItemImages[i], 10, tempy, UI.ToolItemWidth, UI.ToolBarHeight);
			tempy += UI.ToolBarHeight;
			pWind->DrawRectangle(10, tempy, UI.ToolItemWidth, tempy+11, FILLED);
			tempy += 11;

		}*/
	}

	//Draw a line under the toolbar
	pWind->SetPen(GREY, 3);
	pWind->DrawLine(0, UI.ToolBarHeight + 25, UI.width, UI.ToolBarHeight + 25);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	/*UI.AppMode = SIMULATION;*/	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	string MenuItemImages[ITM_SIM_CNT+ MODE_CNT];
	MenuItemImages[DESIGN] = "images\\Menu\\Menu_DES.jpg";
	MenuItemImages[SIMULATION] = "images\\Menu\\Menu_SIM.jpg";
	//MenuItemImages[ITM_SELECT + MODE_CNT] = "images\\Menu\\Menu_SELECT.jpg";
	MenuItemImages[ITM_TRUTH + MODE_CNT] = "images\\Menu\\Menu_Truth.jpg";
	MenuItemImages[ITM_LABEL + MODE_CNT] = "images\\Menu\\Menu_LABEL.jpg";
	MenuItemImages[ITM_EDIT + MODE_CNT] = "images\\Menu\\Menu_EDIT.jpg";
	MenuItemImages[ITM_COPY + MODE_CNT] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_PASTE + MODE_CNT] = "images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_CUT + MODE_CNT] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_DELETE + MODE_CNT] = "images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_UNDO + MODE_CNT] = "images\\Menu\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO + MODE_CNT] = "images\\Menu\\Menu_Redo.jpg";
	MenuItemImages[ITM_MOVE + MODE_CNT] = "images\\Menu\\Menu_Move.jpg";
	MenuItemImages[ITM_SAVE + MODE_CNT] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOAD + MODE_CNT] = "images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_EXIT + MODE_CNT] = "images\\Menu\\Menu_Exit.jpg";

	//MenuItemImages[ITM_CUT] = "images	\\Menu\\Menu_CUT.jpg";

	pWind->SetPen(WHITE);
	int tempx = 10;
	int tempy = UI.SimItemCoordinate;

	//pWind->DrawImage(MenuItemImages[3], tempx, tempy + 20);

	for (int i = 0; i < ITM_SIM_CNT+MODE_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], 10, tempy, 30, 30);
		tempy += UI.SimItemHeight;
		pWind->DrawRectangle(10, tempy, UI.ToolItemWidth, tempy +11 , FILLED);
		tempy += 11;

	}

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_OR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_XNOR2.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);


}void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_AND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINVERTER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_INVERTER_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_INVERTER.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_BUFFER.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gate\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gate\\Gate_NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected , bool Active) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
	{
			GateImage = "Images\\Gate\\LED_Hi.jpg";
	}
	else
	{
		GateImage = "Images\\Gate\\LED.jpg";
	}
	if (Active && UI.AppMode == SIMULATION)
	{
		GateImage = "Images\\Gate\\LED_Active.jpg";
	}

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
	{
		if (UI.AppMode == DESIGN)
			GateImage = "Images\\Gate\\SWITCH_Hi.jpg";
		else
			GateImage = "Images\\Gate\\SWITCH_Active.jpg";
	}
	else 
		GateImage = "Images\\Gate\\SWITCH.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo* points, int count,bool selected) const
{
	//TODO: Add code to draw connection

	    if (selected) pWind->SetPen(RED, 3);
	    else pWind->SetPen(BLACK, 3);
		for (int i = 0; i < count; i++)
		{
			pWind->DrawLine(points[i].x1, points[i].y1, points[i].x2, points[i].y2);
		}

}
void Output::PrintString(GraphicsInfo r_GfxInfo, string m)
{
	pWind->SetPen(BLACK, 3);
	pWind->DrawString((((r_GfxInfo.x1)+(r_GfxInfo.x2))/2)-22, (((r_GfxInfo.y1) + (r_GfxInfo.y2)) / 2)-45, m);
}

Output::~Output()
{
	delete pWind;
}
