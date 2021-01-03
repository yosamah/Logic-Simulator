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
void ApplicationManager::AddComponent(Component* pComp, bool IsLoad)
{
	if (IsLoad)
	{
		CompList[CompCount] = pComp;
		CompList[CompCount++]->SetID(CompCount);
	}
	else
		CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

//int ApplicationManager::getGateNumber(Component* comp)
//{
//	for (int i = 0; i < CompCount; i++)
//	{
//		if (comp == CompList[i])
//			return i;
//	}
//	return -1;
//}
////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteComponent()
{
	OutputInterface->PrintMsg("Press on any item to delete it!");
	int x, y;
	InputInterface->GetPointClicked(x, y);
	Component** c1 = getComponent(x, y);
	
	if (c1 != NULL)
	{
		*c1 = CompList[CompCount - 1];
		CompList[CompCount--] = NULL;
	}
	else
	{
		OutputInterface->PrintMsg("No pressed item! To try again press on Delete.");
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
			pAct = new AddConnection(this);
			break;

		case DEL:
			DeleteComponent();
			break;
		
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
//string ApplicationManager::getString()
//{
//	return InputInterface->GetSrting(OutputInterface,"","");
//}

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetIDGate(int ID)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (ID == CompList[i]->GetID())
			return CompList[i];
	}
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
		Component* c = dynamic_cast<Connection*>(CompList[i]);
		if (c == NULL)
			CompList[i]->Save(file);
	}

	file << "CONNECTIONS" << endl;

	for (int i = 0; i < CompCount; i++)
	{
		Component* c = dynamic_cast<Connection*>(CompList[i]);
		if (c != NULL)
			CompList[i]->Save(file);
	}

	file << "-1 ";
	file.close();

	//Print Action Message
	OutputInterface->PrintMsg("File saved!");
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::Load()
{
	ifstream file;   //clear drawing area
	file.open("Info.txt");
	CompCount = 0;

	Action* pAct = NULL;

	string CompName;
	GraphicsInfo GfxInfo;
	GfxInfo.x1 = -1;
	GfxInfo.y1 = -1;
	GfxInfo.x2 = -1;
	GfxInfo.y2 = -1;

	string Check = InputInterface->GetSrting(OutputInterface, "All unsaved data will be removed. Do you want to continue (y/n):");

	if (Check == "y")
	{
		if (file.is_open())
		{
			while (file >> CompName && CompName != "-1")
			{
				if (CompName == "CONNECTIONS")
				{
					while (!file.eof())
					{
						int IDgate1, IDgate2, PinNo;
						Connection* pA = new Connection();
						pA->Load(file, &IDgate1, &IDgate2, &PinNo);
						if (IDgate1 == -1)
							break;
						Component* SrcCmpnt = GetIDGate(IDgate1);
						Component* DstCmpnt = GetIDGate(IDgate2);
						delete pA;
						pAct = new AddConnection(this, true, SrcCmpnt, DstCmpnt, PinNo);
						pAct->Execute();
					}
					break;
				}

				else if (CompName == "AND2")
				{
					AND2* pA = new AND2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "AND3")
				{
					AND3* pA = new AND3(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "BUFFER")
				{
					BUFFER* pA = new BUFFER(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "INVERTER")
				{
					INVERTER* pA = new INVERTER(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "LED")
				{
					LED* pA = new LED(GfxInfo);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "NAND2")
				{
					NAND2* pA = new NAND2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "NOR2")
				{
					NOR2* pA = new NOR2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "NOR3")
				{
					NOR3* pA = new NOR3(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "OR2")
				{
					OR2* pA = new OR2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "SWITCH")
				{
					SWITCH* pA = new SWITCH(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "XNOR2")
				{
					XNOR2* pA = new XNOR2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "XOR2")
				{
					XOR2* pA = new XOR2(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
				else if (CompName == "XOR3")
				{
					XOR3* pA = new XOR3(GfxInfo, AND2_FANOUT);
					pA->Load(file);
					AddComponent(pA);
				}
			}
			
			OutputInterface->PrintMsg("File loaded!");
		}
		else
		{
			OutputInterface->PrintMsg("File not found!");
		}
	}
	else
		OutputInterface->PrintMsg("File not loaded!");
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
	}
	
	delete OutputInterface;
	delete InputInterface;
	
}
