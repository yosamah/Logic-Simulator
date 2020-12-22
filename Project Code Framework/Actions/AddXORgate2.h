#ifndef _ADD_XOR_GATE_H
#define _ADD_XOR_GATE_H

#include "action.h"
#include "..\Components\XOR2.h"

class AddXORgate2 : public Action
{
private:
	//Parameters fXOR rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two cXORners of the rectangluar area
public:
	AddXORgate2(ApplicationManager* pApp);
	virtual ~AddXORgate2(void);

	//Reads parameters required fXOR action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif