#pragma once

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\ApplicationManager.h"
#include "Delete.h"

class Cut : public Action
{
private:
	GraphicsInfo GfxI;
	Component** Comp;
	bool valid;
public:
	Cut(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
