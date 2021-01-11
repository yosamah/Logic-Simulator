#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :m_OutputPin(r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	active = false;
	m_OutputPin.setPinLocation(80, 25);
}


void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (getSelected())
		m_OutputPin.setSIMStatus(HIGH);
	else
		m_OutputPin.setSIMStatus(LOW);
	//Add you code here
}


int SWITCH::ConnectToOut(Connection* c)
{
	bool x = m_OutputPin.ConnectTo(c);
	if (x)
		return 1;
	return 0;
}

// Function Draw
// Draws SWITCH gate
void SWITCH::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo, selected);
}


//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getSIMStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//No input pins in the switch.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	;
}

void SWITCH::Save(ofstream& file)
{
	file << "SWITCH "<< "\t" << GetID() << "\t" << GetLabel() << "\t" << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << "\t" << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

void SWITCH::Load(ifstream& file, int* IDgate1, int* IDgate2, int* PinNo)
{
	int ID;
	file >> ID;
	SetID(ID);

	string Label;
	file >> Label;

	if (Label == "$")
	{
		Label = " ";
		SetLabel(Label);
	}
	else
		SetLabel(Label);

	int Cx, Cy;
	file >> Cx >> Cy;
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	m_GfxInfo.x1 = Cx - Len / 2;
	m_GfxInfo.x2 = Cx + Len / 2;
	m_GfxInfo.y1 = Cy - Wdth / 2;
	m_GfxInfo.y2 = Cy + Wdth / 2;
}

OutputPin* SWITCH::getOutputPin()
{
	return &(m_OutputPin);
}
int SWITCH::getOutPinLocationX()
{
	return m_OutputPin.getXPinLocation();
}
int SWITCH::getOutPinLocationY()
{
	return m_OutputPin.getYPinLocation();
}

