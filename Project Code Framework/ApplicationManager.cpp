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
#include <fstream>



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
		bool z= CompList[i]->drawArea(x, y);
	
		if (z )
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
		
		case SAVE:
			Save();
			break;

		case LOAD:
			Load();
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

///////////////////////////////////////////////////////////////////

void ApplicationManager::Save()
{
	ofstream file;
	file.open("Info.txt");
	file.clear();
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Save(file);
	}
	file << "-1 ";  //ADD close file
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::Load()
{
	ifstream file;   //clear drawing area
	file.open("Info.txt");

	Action* pAct = NULL;

	string CompName;
	GraphicsInfo GfxInfo;

	if (file.is_open())
	{
		while (file >> CompName && CompName != "-1")
		{

			file >> GfxInfo.x1 >> GfxInfo.y1;

			if (CompName == "AND2")
				pAct = new AddANDgate2(this, &GfxInfo);
			else if (CompName == "AND3")
				pAct = new AddANDgate3(this, &GfxInfo);
			else if (CompName == "BUFFER")
				pAct = new AddBUFFER(this, &GfxInfo);
			else if (CompName == "INVERTER")
				pAct = new AddINVERTER(this, &GfxInfo);
			else if (CompName == "LED")
				pAct = new AddLED(this, &GfxInfo);
			else if (CompName == "NAND2")
				pAct = new AddNANDgate2(this, &GfxInfo);
			else if (CompName == "NOR2")
				pAct = new AddNORgate2(this, &GfxInfo);
			else if (CompName == "NOR3")
				pAct = new AddNORgate3(this, &GfxInfo);
			else if (CompName == "OR2")
				pAct = new AddORgate2(this, &GfxInfo);
			else if (CompName == "SWITCH")
				pAct = new AddSWITCH(this, &GfxInfo);
			else if (CompName == "XNOR2")
				pAct = new AddXNORgate2(this, &GfxInfo);
			else if (CompName == "XOR2")
				pAct = new AddXORgate2(this, &GfxInfo);
			else if (CompName == "XOR3")
				pAct = new AddXORgate3(this, &GfxInfo);


			pAct->Execute();
			delete pAct;
		}
	}
	else
	{
	}


}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
	delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
