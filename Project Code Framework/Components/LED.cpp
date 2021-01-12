#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	Active = false;
	m_InputPin.setPinLocation(30, 50);
}

InputPin* LED::getInputPin(int n)
{
	return &(m_InputPin);
}

void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (m_InputPin.getSIMStatus() == HIGH)
		Active = true;
	else
		Active = false;
	//Add you code here
}

void LED::setActive(bool a)
{
	Active = a;
}
bool LED::getActive()
{
	return Active;
}

int LED::getNoOfInPins()
{
	return 1;
}
int LED::getInPinLocationX(int n)
{
	return m_InputPin.getXPinLocation();
}
int LED::getInPinLocationY(int n)
{
	return m_InputPin.getYPinLocation() ;
}


// Function Draw
// Draws LED gate
void LED::Draw(Output* pOut, bool selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo, selected,Active);
}



//returns status of outputpin
int LED::GetOutPinStatus()
{
	// There is no output in the led
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}

void LED::Save(ofstream& file)
{
	file << "LED " << "\t\t" << GetID() << "\t" << GetLabel() << "\t" << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << "\t" << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
}

void LED::Load(ifstream& file, int* IDgate1 , int* IDgate2, int* PinNo)
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