#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
	{
		m_InputPins[i].setComponent(this);
		m_InputPins[i].setStatus(LOW);
	}
		

	m_InputPins[0].setPinLocation(0, 13);
	if (m_Inputs == 2)
	{
		m_InputPins[1].setPinLocation(0, 36);
	}
	if (m_Inputs == 3)
	{
		m_InputPins[1].setPinLocation(0, 25);
		m_InputPins[2].setPinLocation(0, 36);
	}

	m_OutputPin.setPinLocation(80, 25);
}

int Gate::getInPinLocationX(int n)
{
	return m_InputPins[n].getXPinLocation();
}
int Gate::getInPinLocationY(int n)
{
	return m_InputPins[n].getYPinLocation();
}
int Gate::getOutPinLocationX()
{
	return m_OutputPin.getXPinLocation();
}
int Gate::getOutPinLocationY()
{
	return m_OutputPin.getYPinLocation();
}
int Gate::getNoOfInPins()
{
	return m_Inputs;
}


InputPin* Gate::getInputPin(int n)
{
	return &(m_InputPins[n]);
}

OutputPin* Gate::getOutputPin()
{
	return &(m_OutputPin);
}