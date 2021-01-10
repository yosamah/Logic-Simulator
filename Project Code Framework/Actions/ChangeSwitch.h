#pragma once


#include "action.h"
#include "..\Components\SWITCH.h"

class ChangeSwitch : public Action
{
private:
	GraphicsInfo GfxI;
	bool valid;
	Component** Comp;

public:
	ChangeSwitch(ApplicationManager* pApp);

	virtual ~ChangeSwitch(void);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
