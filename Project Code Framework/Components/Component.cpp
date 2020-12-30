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