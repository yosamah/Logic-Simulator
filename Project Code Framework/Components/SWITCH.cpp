#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut) 
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws SWITCH gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo);
}


//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//No input pins in the switch.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void SWITCH::Save(ofstream& file)
{
	file << "SWITCH " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}