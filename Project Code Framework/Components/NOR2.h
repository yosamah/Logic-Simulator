#ifndef _NOR2_H
#define _NOR2_H

/*
  Class NOR2
  -----------
  represent the 2-input NOR gate
*/

#include "Gate.h"

class NOR2 :public Gate
{
public:
	NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut, bool selected = 0);	//Draws 2-input gate
	virtual void Save(ofstream& file);
	virtual void Load(ifstream& file, int* IDgate1 = NULL, int* IDgate2 = NULL, int* PinNo = NULL);


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif
