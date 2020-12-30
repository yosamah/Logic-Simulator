#ifndef _ADD_AND_GATE_3_H
#define _ADD_AND_GATE_3_H


#include "action.h"
#include "..\Components\AND3.h"

class AddANDgate3 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	bool Loaded;  //Checking if the Adding is from the user click or loaded from external file
	GraphicsInfo LoadC;
public:
	AddANDgate3(ApplicationManager* pApp);
	AddANDgate3(ApplicationManager* pApp, GraphicsInfo* G);

	virtual ~AddANDgate3(void);

	//Reads parameters required fAND action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
