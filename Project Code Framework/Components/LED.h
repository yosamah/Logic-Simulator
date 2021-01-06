#ifndef _LED_H
#define _LED_H

/*
  Class LED
  -----------
  represent the LED gate
*/

#include "Component.h"

class LED :public Component
{
	InputPin m_InputPin;	//Input pins of the LED.
	
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file, int* IDgate1 = NULL, int* IDgate2 = NULL, int* PinNo = NULL);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	int getInPinLocationX(int n);
	int getInPinLocationY(int n);
	int getNoOfInPins();
	

	InputPin* getInputPin(int n);

};

#endif
