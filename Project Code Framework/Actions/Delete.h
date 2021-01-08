#ifndef _DELETE_H
#define _DELETE_H
#include "action.h"

class Delete: public Action
{
	int x1, y1;

public:
	Delete(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();

	
	virtual void Execute();

	
	virtual void Undo();

	
	virtual void Redo();

};

#endif