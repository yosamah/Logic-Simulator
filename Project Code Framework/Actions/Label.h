#ifndef _LABEL_H
#define _LABEL_H
#include "action.h"

class Label : public Action
{
	int x1, y1;

public:
	Label(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();


	virtual void Execute();


	virtual void Undo();


	virtual void Redo();

};

#endif