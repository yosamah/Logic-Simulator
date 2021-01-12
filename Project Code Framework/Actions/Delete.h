#ifndef _DELETE_H
#define _DELETE_H
#include "action.h"
#include "..\Components\Connection.h"


class Delete: public Action
{
	int x1, y1;
	Component* pA;
	int countDel;

public:
	Delete(ApplicationManager* pApp, Component* p = NULL);
	virtual void ReadActionParameters();

	
	virtual void Execute();

	
	virtual void Undo();

	
	virtual void Redo();

};

#endif