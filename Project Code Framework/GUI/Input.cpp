//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
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

	pWind->FlushKeyQueue();

	keytype k;
	char c;
	string m = "";


	do
	{
		pOut->PrintMsg(m);
		k = pWind->WaitKeyPress(c);

		switch (k)
		{

		case BACK:
			if (m.length() != 0)
			{
				m.pop_back();
			}
			break;

		case ESCAPE:
			m.clear();
			pOut->PrintMsg(m);
			break;

		case RETURN:
			pWind->DrawString(500, 500, m);
			break;

		default:
			if (c == '\b')
				break;
			m.push_back(c);
			break;
		}

	} while (k != RETURN && k != ESCAPE);

	pWind->FlushMouseQueue();
	return m;


}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	int temp = UI.ToolBarHeight + 135;
	int ClickedItemOrderSim = (y / (UI.SimItemHeight + 11 + temp));
	if (x <= UI.ToolItemWidth && y > temp && y < temp + 2*(UI.SimItemHeight+11))
	{
		if (ClickedItemOrderSim == 1)
			UI.AppMode = SIMULATION;
		if (ClickedItemOrderSim == 0)
		{
			UI.AppMode = DESIGN;
			pWind->WaitMouseClick(x, y);
		}
			
	}
	
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight )
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / (UI.ToolItemWidth + 11));
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_BUFFER: return ADD_Buff;
			case ITM_INVERTER: return ADD_INV;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_WIRE: return ADD_CONNECTION;
			case ITM_LED: return ADD_LED;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		
		if((y < temp && y >= UI.ToolBarHeight && x <= UI.ToolItemWidth) || ((y >(ITM_SIM_CNT + MODE_CNT)*41-11))&& (y < UI.height - UI.StatusBarHeight) && x <= UI.ToolItemWidth)
			return SELECT;
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x >= UI.ToolItemWidth)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		
		if (x <= UI.ToolItemWidth)
		{

		}
		
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
