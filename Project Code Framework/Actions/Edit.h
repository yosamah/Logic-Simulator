#ifndef _EDIT_H
#define _EDIT_H
#include "action.h"

class Edit : public Action
{
	int x1, y1;

public:
	Edit(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();


	virtual void Execute();


	virtual void Undo();


	virtual void Redo();

};

#endif