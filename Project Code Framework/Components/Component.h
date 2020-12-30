#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "InputPin.h"
#include "OutputPin.h"


//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	  //Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself

	virtual OutputPin* getOutputPin();
	virtual InputPin* getInputPin(int n);

	bool InDrawingArea(int Cx, int Cy);    //Checks if the point clicked is in drawing area
	bool drawArea(int x, int y);
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	void setXConnection(int& x);
	void setYConnection(int& y);

	void setXOutConnection(int& x);
	void setYOutConnection(int& y);

	virtual int getInPinLocationX(int n) ;
	virtual int getInPinLocationY(int n);
	virtual int getOutPinLocationX();
	virtual int getOutPinLocationY();
	virtual int getNoOfInPins();

	int checkMargin(int y, int n);


	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	virtual void Save(ofstream& file) = 0;
	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
