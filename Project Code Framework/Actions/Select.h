#ifndef _SELECT_H
#define _SELECT_H
#include "action.h"
#include "..\Components\Connection.h"


class Select : public Action
{
	int x1, y1;
	Component** pComp;

public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();


	virtual void Execute();
	virtual void Undo();


	virtual void Redo();

};

#endif

