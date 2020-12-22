#ifndef _ADD_NOR_GATE_H
#define _ADD_NOR_GATE_H

#include "action.h"
#include "..\Components\NOR2.h"

class AddNORgate2 : public Action
{
private:
	//Parameters fNOR rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two cNORners of the rectangluar area
public:
	AddNORgate2(ApplicationManager* pApp);
	virtual ~AddNORgate2(void);

	//Reads parameters required fNOR action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif