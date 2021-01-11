#pragma once
#include <fstream>
#include "action.h"
#include "..\ApplicationManager.h"

class LoadAction : public Action
{
private:
	ifstream file;
	bool valid;
public:
	LoadAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};