#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < m_Inputs; i++) {
		if (m_InputPins[i].getSIMStatus() == HIGH) {
			m_OutputPin.setSIMStatus(LOW);
			return;
		}
	}
	m_OutputPin.setSIMStatus(HIGH);
	//Add you code here
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, selected);
}


//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR3::Save(ofstream& file)
{
	file << "NOR3 "<< "\t\t" << GetID() << "\t" << GetLabel() << "\t" << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << "\t" << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

void NOR3::Load(ifstream& file, int* IDgate1, int* IDgate2, int* PinNo)
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