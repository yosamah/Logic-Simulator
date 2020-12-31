#ifndef _ADD_INVERTER_H
#define _ADD_INVERTER_H

#include "action.h"
#include "..\Components\INVERTER.h"

class AddINVERTER : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

	bool Loaded;  //Checking if the Adding is from the user click or loaded from external file
	GraphicsInfo LoadC;

public:
	AddINVERTER(ApplicationManager* pApp);
	AddINVERTER(ApplicationManager* pApp, GraphicsInfo* G);

	virtual ~AddINVERTER(void);

	//Reads parameters required fINVERTER action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif