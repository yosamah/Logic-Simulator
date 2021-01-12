#pragma once

#include "action.h"
#include "..\Components\Component.h"
#include "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\SWITCH.h"
#include "..\Components\Connection.h"
#include "..\ApplicationManager.h"



class TruthTable : public Action
{
private:
	int InCnt;
	int OutCnt;
	SWITCH** Switches;
	LED** Leds;
	int* original;
	int rows;
	int cols;
	//bool ok;
	ofstream truth;
	int** perm;
public:
	TruthTable(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	virtual void Save();
	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo() {}

	//To redo this action (code depends on action type)
	virtual void Redo() {}

};
