#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::setPinLocation(int a, int b)
{
	x = a;
	y = b;
}