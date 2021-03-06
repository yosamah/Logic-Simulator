#ifndef _SWITCH_H
#define _SWITCH_H

/*
  Class SWITCH
  -----------
  represent the SWITCH gate
*/

#include "Component.h"

class SWITCH :public Component
{
	OutputPin m_OutputPin;	//The Gate output pin
	bool active;
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut, bool selected = 0);	//Draws 1-input gate
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file, int* IDgate1 = NULL, int* IDgate2 = NULL, int* PinNo = NULL);

	virtual bool GetOutStatus();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	OutputPin* getOutputPin();
	int getOutPinLocationX();
	int getOutPinLocationY();
	int ConnectToOut(Connection* c);

};

#endif
#pragma once
