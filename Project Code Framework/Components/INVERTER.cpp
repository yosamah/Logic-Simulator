#include "INVERTER.h"

INVERTER::INVERTER(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INVERTER::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	m_OutputPin.setSIMStatus((STATUS)!m_InputPins[m_Inputs - 1].getSIMStatus());
	//Add you code here
}


// Function Draw
// Draws INVERTER gate
void INVERTER::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINVERTER(m_GfxInfo, selected);
}


//returns status of outputpin
int INVERTER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INVERTER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INVERTER::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void INVERTER::Save(ofstream& file)
{
	file << "INVERTER " << "\t" << GetID() << "\t" << GetLabel() << "\t" << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << "\t" << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

void INVERTER::Load(ifstream& file, int* IDgate1 , int* IDgate2 , int* PinNo)
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