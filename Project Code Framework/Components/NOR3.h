#ifndef _NOR3_H
#define _NOR3_H

/*
  Class NOR3
  -----------
  represent the 3-input NOR gate
*/

#include "Gate.h"

class NOR3 :public Gate
{
public:
	NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOR gate
	virtual void Draw(Output* pOut, bool selected = 0);	//Draws 3-input gate
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file, int* IDgate1 = NULL, int* IDgate2 = NULL, int* PinNo = NULL);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif

