#pragma once

#include "action.h"
#include "..\ApplicationManager.h"

class Select : public Action
{
private:
	GraphicsInfo GfxI;
	Component** Comp;
	bool valid;
public:
	Select(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};