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
#include "Actions\Delete.h"
#include "Actions\Copy.h"
#include "Actions\Label.h"
#include "Actions\Edit.h"
#include "Actions\Paste.h"
#include "Actions\Cut.h"
#include "Actions\Select.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ChangeSwitch.h"
#include <fstream>



ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	CopyComp = NULL;
	for (int i = 0; i < MaxCompCount; i++) {
		CompList[i] = NULL;
	}

	CurrMode = DESIGN;
	PrevMode = DESIGN;

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

		int count = 1;
		Component* c = dynamic_cast<Connection*>(CompList[CompCount]);

		if (c != NULL)
		{
			for (int i = 0; i < CompCount; i++)
			{
				if (CompList[i]->GetID() == count)
				{
					count = i + 2;
				}

			}
			CompList[CompCount]->SetID(count);
		}

		CompCount++;
	}
	else
	{
		CompList[CompCount] = pComp;
		CompList[CompCount++]->SetID(CompCount);
	}
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


//void ApplicationManager::SelectComponent() {
//	
//	//Farah: 
//	int x, y;
//	InputInterface->GetPointClicked(x, y);
//	Component** pComp=getComponent(x,y); 
//	if (pComp != NULL) {
//		if ((*pComp)->getSelected() == 0) {
//			(*pComp)->setSelected(1);
//		}
//		else {
//			(*pComp)->setSelected(0);
//		}
//		UpdateInterface();
//	}
//}



void ApplicationManager::RemoveConnection(Component** c1)
{
	Component* c2 = (*c1)->GetDestinationGate();
	(c2)->removeConToOut((Connection*)*c1);
	Component* c3 = (*c1)->GetSourceGate();
	int destPin = (*c1)->GetDPin();
	c3->setInputPinStatus(destPin + 1, LOW);
	int ID = CompList[CompCount - 1]->GetID();
	*c1 = CompList[CompCount - 1];
	(*c1)->SetID(ID);
	CompList[--CompCount] = NULL;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::RemoveComponent(Component** c1)
{
	bool checkExist = 0;
	for (int i = 0;i < CompCount;i++) {
		if (*c1 == CompList[i]) {
			checkExist = 1;
			c1 = &CompList[i];
			break;
		}
	}
	if (checkExist == 1) {
		int ID = CompList[CompCount - 1]->GetID();
		Component* removedComp = dynamic_cast<Connection*>(*c1);
		if (removedComp != NULL)
		{
			RemoveConnection(c1);
		}
		else
		{
			int i = 0;
			while (i < CompCount)
			{
				Component* ConnectionGate = dynamic_cast<Connection*>(CompList[i]);
				if (ConnectionGate)
				{
					if ((*c1) == CompList[i]->GetDestinationGate() || (*c1) == CompList[i]->GetSourceGate())
					{
						RemoveConnection(&CompList[i]);
						i = -1;
					}
				}
				i++;
			}
			*c1 = CompList[CompCount - 1];
			(*c1)->SetID(ID);
			CompList[--CompCount] = NULL;
		}
	}
}

////////////////////////////////////////////////////////////////////
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
	//We keep track of previous and current modes to reset selected components between the two modes.
	PrevMode = CurrMode;
	CurrMode = UI.AppMode;

	if ((UI.AppMode == SIMULATION && PrevMode == DESIGN) || (UI.AppMode == DESIGN && PrevMode == SIMULATION))
	{
		for (int i = 0; i < CompCount; i++)
		{
			CompList[i]->setSelected(0);
		}
	}

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

		case ADD_Label:
			pAct = new Label(this);
			break;

		case EDIT_Label:
			pAct = new Edit(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;
		
		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case CUT:
			pAct = new Cut(this);
			break;

		case Change_Switch:
			CheckSimulation();
			pAct = new ChangeSwitch(this);
			break;
	
		case SELECT:
			pAct = new Select(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{

		pAct->Execute();
		if (UI.AppMode == SIMULATION)
		{
			CheckSimulation();
		}
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(OutputInterface, CompList[i]->getSelected());
		CompList[i]->Draw_Label(OutputInterface);
	}
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::CheckSimulation()
{
	bool Valid = true;

	for (int i = 0; i < CompCount; i++)
	{
		Component* comp = dynamic_cast<SWITCH*>(CompList[i]);
		if (comp)
		{
			if (CompList[i]->GetOutStatus() == LOW)
			{
				Valid = false;
				break;
			}
			else continue;
		}

		int NoPins = CompList[i]->getNoOfInPins();

		for (int j = 1; j <= NoPins; j++)
		{
			if (CompList[i]->GetInputPinStatus(j) == LOW)
			{
				Valid = false;
				break;
			}
		}
	}
	
	if (!Valid)
	{
		OutputInterface->PrintMsg("Circuit is wrong! Switching to design mode ... ");
		UI.AppMode = DESIGN;
		return;
	}

	for (int i = 0; i < CompCount; i++)
	{
		for (int j = 0; j < CompCount; j++)
		{
			CompList[j]->Operate();
		}
	}
	UpdateInterface();
}

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

void ApplicationManager::Save(ofstream& file)
{
	int count = 0;

	for (int i = 0; i < CompCount; i++)
	{
		Component* c = dynamic_cast<Connection*>(CompList[i]);
		if (c == NULL)
			count++;
	}
	file << count << endl;

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

void ApplicationManager::Load(ifstream& file)
{
	//ifstream file;   //clear drawing area
	//file.open("Info.txt");
	CompCount = 0;

	Action* pAct = NULL;

	string CompName;
	GraphicsInfo GfxInfo;
	GfxInfo.x1 = -1;
	GfxInfo.y1 = -1;
	GfxInfo.x2 = -1;
	GfxInfo.y2 = -1;
	
	int count;
	file >> count;

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
				Component* DstCmpnt = GetIDGate(IDgate1);
				Component* SrcCmpnt = GetIDGate(IDgate2);
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
			AddComponent(pA, true);
		}
		else if (CompName == "AND3")
		{
			AND3* pA = new AND3(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "BUFFER")
		{
			BUFFER* pA = new BUFFER(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "INVERTER")
		{
			INVERTER* pA = new INVERTER(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "LED")
		{
			LED* pA = new LED(GfxInfo);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "NAND2")
		{
			NAND2* pA = new NAND2(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "NOR2")
		{
			NOR2* pA = new NOR2(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "NOR3")
		{
			NOR3* pA = new NOR3(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "OR2")
		{
			OR2* pA = new OR2(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "SWITCH")
		{
			SWITCH* pA = new SWITCH(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "XNOR2")
		{
			XNOR2* pA = new XNOR2(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "XOR2")
		{
			XOR2* pA = new XOR2(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
		else if (CompName == "XOR3")
		{
			XOR3* pA = new XOR3(GfxInfo, AND2_FANOUT);
			pA->Load(file);
			AddComponent(pA, true);
		}
	}

	OutputInterface->PrintMsg("File loaded!");
}
		
	//	else
		//{
		//	OutputInterface->PrintMsg("File not found!");
		//}
	//}
	//else
	//	OutputInterface->PrintMsg("File not loaded!");
////////////////////////////////////////////////////////////////////

void ApplicationManager::SetCopiedComponent(Component* Comp)
{CopyComp = Comp;}

Component* ApplicationManager::GetCopiedComponent()
{return CopyComp;}
////////////////////////////////////////////////////////////////////

Component** ApplicationManager::GetSelectedComponent(int& count) {
	Component** SelectedArr;
	for (int i = 0;i < CompCount;i++) {
		if (CompList[i]->getSelected()) count++;
	}
	SelectedArr = new Component*[count];
	int k(0);
	for (int i = 0;i < CompCount;i++) {
		if (CompList[i]->getSelected() && k<count) SelectedArr[k] = CompList[i], k++;
	}
	return SelectedArr;
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
