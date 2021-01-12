#ifndef _EDIT_H
#define _EDIT_H
#include "action.h"
#include "..\Components\Connection.h"

class Edit : public Action
{
	int x1, y1;
	Component* comp2;
	Component* comp1;
	bool checkDestGate;
	bool checkSourceGate;
	Component** newComp;
	Component** comp;
	string testLabel;
	Component* testConnection;
	string oldLabel;
	int pinN;
	int oldPin;
	string newLabel;

public:
	Edit(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();


	virtual void Execute();


	virtual void Undo();


	virtual void Redo();

};

#endif