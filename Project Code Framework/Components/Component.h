#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "InputPin.h"
#include "OutputPin.h"


//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	bool selected;
	int m_ID;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	string m_Label;
	int pointsCount;
	GraphicsInfo* pointsArray;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	void setSelected(bool);
	bool getSelected();
	virtual void Operate() = 0;	  //Calculates the output according to the inputs
	virtual void Draw(Output* pOut, bool selected = 0) = 0;	//for each component to Draw itself
    virtual void Draw_Label(Output* pOut); //Draw Label for each component
	virtual OutputPin* getOutputPin();
	virtual InputPin* getInputPin(int n);
	bool InDrawingArea(int Cx, int Cy);    //Checks if the point clicked is in drawing area
	bool drawArea(int x, int y);
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual bool GetOutStatus();

	void setXConnection(int& x);
	void setYConnection(int& y);

	virtual int getPointsCount();
	virtual GraphicsInfo* getPointsArray();

	void setXOutConnection(int& x);
	void setYOutConnection(int& y);

	virtual int ConnectToOut(Connection* c);
	virtual void removeConToOut(Connection* c);
	virtual int changeSrc(Component* srcGate) { return - 1; };
	virtual int changeDst(Component* dstGate, int pinDest) { return -1; };

	virtual Component* GetSourceGate();
	virtual Component* GetDestinationGate();
	virtual int GetDPin();

	virtual int getInPinLocationX(int n) ;
	virtual int getInPinLocationY(int n);
	virtual int getOutPinLocationX();
	virtual int getOutPinLocationY();
	virtual int getNoOfInPins();

	int checkMargin(int y, int n);

	void SetID(int ID);
	int GetID();
	Component* GetIDGate(int ID);

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	virtual void Save(ofstream& file) = 0;

    void SetLabel(string &label); //Set label of component
	string GetLabel();            //Get label of component

	virtual void Load(ifstream& file , int *IDgate1 = NULL, int *IDgate2 = NULL, int *PinNo = NULL) = 0;

	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
