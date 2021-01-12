#ifndef _LABEL_H
#define _LABEL_H
#include "action.h"
#include "..\ApplicationManager.h"

class Label : public Action
{
	int x1, y1;
	string oldLabel;
	string newLabel;
	Component** comp;

public:
	Label(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();


	virtual void Execute();


	virtual void Undo();


	virtual void Redo();

};

#endif