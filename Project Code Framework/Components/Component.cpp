#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

bool Component::InDrawingArea(int Cx, int Cy)
{
	if (Cy >= (UI.ToolBarHeight + UI.GateMarginY + 21) && Cy < (UI.height - UI.StatusBarHeight - UI.GateMarginY) && Cx >= (UI.ToolItemWidth) && Cx <= (UI.width - UI.GateMarginX))
		return true;
	if ((Cy < (UI.SimItemCoordinate - UI.GateMarginY) && Cy >= (UI.ToolBarHeight + UI.GateMarginY + 21) && Cx <= UI.ToolItemWidth && Cx >= UI.GateMarginX) || ((Cy > (ITM_SIM_CNT + MODE_CNT) * 40 + UI.SimItemCoordinate)) && (Cy < (UI.height - UI.StatusBarHeight)) && Cx <= UI.ToolItemWidth && Cx >= UI.GateMarginX)
		return true;
	return false;
}

Component::Component()
{}

Component::~Component()
{}

bool Component:: drawArea(int x, int y)
{
	bool z = (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2) ? true : false;
	bool f = (y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) ? true : false;
	if (z && f)
		return true;
	return false;
}

int Component::checkMargin(int y, int n)
{
	if (n == 3)
	{
		int y1 = 15 + m_GfxInfo.y1;
		int y2 = 35 + m_GfxInfo.y1;
		if (y - y1 < 0)
			return 0;
		else if (y - y2 < 0)
			return 1;
		else
			return 2;
	}
	else if (n==2)
	{
		int y1 = 25 + m_GfxInfo.y1;
		if (y - y1 < 0)
			return 0;
		else
			return 1;
	}
	else
	{
		return 0;
	}
}

int Component::getInPinLocationX(int n)
{ 
	return -1;
}
int Component::getInPinLocationY(int n)
{
	return -1;
}
int Component::getOutPinLocationX() 
{
	return -1; 
}
int Component::getOutPinLocationY() 
{
	return -1; 
}
int Component::getNoOfInPins() 
{ 
	return -1; 
}


OutputPin* Component::getOutputPin()
{ 
	return NULL; 
}

int  Component::ConnectToOut(Connection* c)
{
	return -1;
}
InputPin* Component::getInputPin(int n) 
{
	return NULL;
}

void Component::setXConnection(int& x)
{
	x += m_GfxInfo.x1;
}
void Component::setYConnection(int& y)
{
	y += m_GfxInfo.y1;
}

void Component::setXOutConnection(int& x)
{
	x = m_GfxInfo.x2;
}
void Component::setYOutConnection(int& y)
{
	y = m_GfxInfo.y2 -y;
}

void Component::SetID(int ID)
{
	m_ID = ID;
}

int Component::GetID()
{
	return m_ID;
}

Component* Component::GetIDGate(int ID)
{
	if (m_ID == ID)
		return this;
}