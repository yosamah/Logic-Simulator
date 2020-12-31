#ifndef _ADD_NAND_2_GATE_H
#define _ADD_NAND_2_GATE_H

#include "action.h"
#include "..\Components\NAND2.h"

class AddNANDgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	bool Loaded;  //Checking if the Adding is from the user click or loaded from external file
	GraphicsInfo LoadC;

public:
	AddNANDgate2(ApplicationManager *pApp);
	AddNANDgate2(ApplicationManager* pApp, GraphicsInfo* G);

	virtual ~AddNANDgate2(void);
	GraphicsInfo GfxInfo;

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif