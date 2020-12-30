#include "BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFFER::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws Buffer gate
void BUFFER::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo);
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUFFER::Save(ofstream& file)
{
	file << "BUFFER " << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}