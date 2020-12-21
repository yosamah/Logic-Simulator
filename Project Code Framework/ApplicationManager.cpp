#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"



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

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////
//ADD_AND_GATE_2,		//Add 2-input AND gate
//ADD_OR_GATE_2,		//Add 2-input OR gate
//ADD_NAND_GATE_2,	//Add 2-input NAND gate
//ADD_NOR_GATE_2,		//Add 2-input NOR gate
//ADD_XOR_GATE_2,		//Add 2-input XOR gate
//ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
//ADD_AND_GATE_3,		//Add 3-input AND gate
//ADD_NOR_GATE_3,		//Add 3-input NOR gate
//ADD_XOR_GATE_3,		//Add 3-input XOR gate
//ADD_Buff,			//Add 1-input Buffer gate
//ADD_INV,			//Add 1-input Inverter gate
//ADD_Switch,			//Add Switch
//ADD_LED,	        //Add LED

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


		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
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
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

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