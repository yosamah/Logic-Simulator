#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddConnection.h"
#include "Actions\AddBUFF.h"
#include "Actions\AddINVERTER.h"
#include "Actions\AddLED.h"
#include "Actions\AddSWITCH.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteComponent()
{
	int x, y;
	InputInterface->GetPointClicked(x, y);
	Component** c1 = getComponent(x, y);
	
	if (c1 != NULL)
	{
		*c1 = CompList[CompCount - 1];
		CompList[CompCount--] = NULL;
	}
	
	

}


Component** ApplicationManager::getComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		GraphicsInfo gInfo = CompList[i]->getDrawPoint();
		bool z = (x >= gInfo.x1 && x <= gInfo.x2) ? true : false;
		bool f = (y >= gInfo.y1 && y <= gInfo.y2) ? true : false;
		if (z && f)
			return &CompList[i]; 
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////


void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case ADD_Buff:
			pAct = new AddBUFFER(this);
			break;

		case ADD_INV:
			pAct = new AddINVERTER(this);
			break;

		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;

		case ADD_CONNECTION:
			//pAct = new AddConnection(this);
			break;
		case DEL:
			DeleteComponent();
			
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(OutputInterface);
		

}
string ApplicationManager::getString()
{
	return InputInterface->GetSrting(OutputInterface);
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
	delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}