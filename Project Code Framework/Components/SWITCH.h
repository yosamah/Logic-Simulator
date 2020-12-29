#ifndef _SWITCH_H
#define _SWITCH_H

/*
  Class SWITCH
  -----------
  represent the SWITCH gate
*/

#include "Gate.h"

class SWITCH :public Gate
{
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual void Save(ofstream& file);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif
#pragma once
