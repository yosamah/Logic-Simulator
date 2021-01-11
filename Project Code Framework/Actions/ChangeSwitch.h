#pragma once


#include "action.h"
#include "..\Components\SWITCH.h"
#include "..\Components\Component.h"
#include "..\ApplicationManager.h"

class ChangeSwitch : public Action
{
private:
	GraphicsInfo GfxI;
	bool valid;
	Component** Comp;
	Component* Comp2;

public:
	ChangeSwitch(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
