#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H


#include "action.h"
#include "..\Components\Connection.h"

class AddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	GraphicsInfo GInfo; //Two points of connection.
	OutputPin* pSrcPin;
	InputPin* pDstPin;
	
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
