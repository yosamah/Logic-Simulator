#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	
}
void Component::setSelected(bool x) {
	selected = x;
}

bool Component::getSelected() {
	return selected;
}

Component::Component()
{
	selected = 0;
}

Component::~Component()
{}

