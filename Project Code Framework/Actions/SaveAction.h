#pragma once
#include <fstream>
#include "action.h"
#include "..\ApplicationManager.h"

class SaveAction : public Action
{
private:
	ofstream file;
public:
	SaveAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};