#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	selected = 0;
	m_GfxInfo = r_GfxInfo;	
	pointsCount = -1;
	pointsArray = NULL;
}
void Component::setSelected(bool x) {
	selected = x;
}

bool Component::getSelected() {
	return selected;
}

bool Component::InDrawingArea(int Cx, int Cy)
{
	if (Cy >= (UI.ToolBarHeight + UI.GateMarginY + 21) && Cy < (UI.height - UI.StatusBarHeight - UI.GateMarginY) && Cx >= (UI.ToolItemWidth) && Cx <= (UI.width - UI.GateMarginX))
		return true;
	if ((Cy < (UI.SimItemCoordinate - UI.GateMarginY) && Cy >= (UI.ToolBarHeight + UI.GateMarginY + 21) && Cx <= UI.ToolItemWidth && Cx >= UI.GateMarginX) || ((Cy > (ITM_SIM_CNT + MODE_CNT) * 40 + UI.SimItemCoordinate)) && (Cy < (UI.height - UI.StatusBarHeight)) && Cx <= UI.ToolItemWidth && Cx >= UI.GateMarginX)
		return true;
	return false;
}

void Component::SetLabel(string& label)
{
	if (!label.empty())
		m_Label = label;
}

string Component::GetLabel()
{
	if (!m_Label.empty())
		return m_Label;
	else
		return "$";
}


Component::Component()
{
	selected = 0;
}

Component::~Component()
{}

bool Component:: drawArea(int x, int y)
{
	bool z = (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2) ? true : false;
	bool f = (y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) ? true : false;
	if (z && f)
		return true;
	bool DrawConnection = false;
	for (int i = 0; i < pointsCount; i++)
	{
		bool test1 = (x > pointsArray[i].x1-3 && x < pointsArray[i].x2+3) ? true : false;
		bool test2 = (y > pointsArray[i].y1-3 && y < pointsArray[i].y2+3) ? true : false;
		if (test1 && test2)
			DrawConnection = true;
	}
	if (DrawConnection)
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


int Component::getPointsCount()
{
	return -1;
}
GraphicsInfo* Component::getPointsArray()
{
	return NULL;
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
Component* Component::GetSourceGate()
{
	return NULL;
}
Component* Component::GetDestinationGate()
{

	return NULL;
}
int Component::GetDPin()
{
	return -1;
}

void Component::Draw_Label(Output* pOut)
{
	pOut->PrintString(m_GfxInfo, m_Label);
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
void Component::removeConToOut(Connection* c)
{};
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

