#ifndef _ADD_BUFF_H
#define _ADD_BUFF_H

#include "action.h"
#include "..\Components\BUFFER.h"

class AddBUFFER : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area

public:
	AddBUFFER(ApplicationManager* pApp);

	virtual ~AddBUFFER(void);

	//Reads parameters required fBUFFER action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif