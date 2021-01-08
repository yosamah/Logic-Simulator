#pragma once

#include "action.h"
#include "AddANDgate2.h"
#include "AddORgate2.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddXORgate2.h"
#include "AddXNORgate2.h"
#include "AddANDgate3.h"
#include "AddNORgate3.h"
#include "AddXORgate3.h"
#include "AddConnection.h"
#include "AddBUFF.h"
#include "AddINVERTER.h"
#include "AddLED.h"
#include "AddSWITCH.h"
#include "..\ApplicationManager.h"

class Paste : public Action
{
private:
	Action* Act;
	Component* Comp;
	bool valid;
public:
	Paste(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};