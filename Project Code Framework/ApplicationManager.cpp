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

void ApplicationManager::SelectComponent() {
	
	//Farah: 
	Component** pComp; //to-do: handle NULL pointer, print msg
	if ((*pComp)->getSelected() == 0) {
		(*pComp)->Draw(OutputInterface, 1);
		(*pComp)->setSelected(1);
	}
	else {
		(*pComp)->Draw(OutputInterface, 0);
		(*pComp)->setSelected(0);
	}
	/* Gate* gatePT = dynamic_cast<Gate*>(pComp); 
	if (gatePT) {
		AND2* compPT = dynamic_cast<AND2*>(gatePT); 
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1); //Farah: try to use pComp instead
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		AND3* compPT = dynamic_cast<AND3*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		BUFFER* compPT = dynamic_cast<BUFFER*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		INVERTER* compPT = dynamic_cast<INVERTER*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		NAND2* compPT = dynamic_cast<NAND2*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		NOR2* compPT = dynamic_cast<NOR2*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		NOR3* compPT = dynamic_cast<NOR3*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		OR2* compPT = dynamic_cast<OR2*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		XNOR2* compPT = dynamic_cast<XNOR2*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		XOR2* compPT = dynamic_cast<XOR2*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		XOR3* compPT = dynamic_cast<XOR3*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		LED* compPT = dynamic_cast<LED*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
		SWITCH* compPT = dynamic_cast<SWITCH*>(gatePT);
		if (compPT) {
			if (pComp->selected == 0) {
				compPT->Draw(OutputInterface, 1);
				pComp->selected = 1;
			}
			else {
				compPT->Draw(OutputInterface, 0);
				pComp->selected = 0;
			}
			return;
		}
	}
	else {
	if (pComp->selected == 0) {
		pComp->Draw(OutputInterface, 1);
		pComp->selected = 1;
	}
	else {
		pComp->Draw(OutputInterface, 0);
		pComp->selected = 0;
	}
	} */
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i] = CompList[CompCount];
	}
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////
// ADD_AND_GATE_2,		//Add 2-input AND gate
//ADD_OR_GATE_2,		//Add 2-input OR gate
//ADD_NAND_GATE_2,	    //Add 2-input NAND gate
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
	
		case SELECT:
			SelectComponent();
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