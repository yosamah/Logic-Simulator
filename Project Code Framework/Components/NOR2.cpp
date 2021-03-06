#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR2::Operate()
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
// Draws 2-input AND gate
void NOR2::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, selected);
}


//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH NOR LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::Save(ofstream& file)
{
	file << "NOR2 "<< "\t\t" << GetID() << "\t" << GetLabel() << "\t" << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << "\t" << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

void NOR2::Load(ifstream& file, int* IDgate1, int* IDgate2, int* PinNo)
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