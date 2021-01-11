#include "Delete.h"
#include <iostream>
using namespace std;
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"


Delete::Delete(ApplicationManager* pApp, Component* p):Action(pApp)
{
	pA = p;
}
	
void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Press on any item to delete it!");
	pIn->GetPointClicked(x1, y1);

	pOut->ClearStatusBar();
}


void Delete::setArrayDel(Component** Array, int count)
{
	numberDeletedItems = count;
	ArrayDeleted = new Component * [numberDeletedItems];
	for (int i = 0; i < count; i++)
		ArrayDeleted[i] = Array[i];

}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	int count = 0;
	Component** SelectedArr = pManager->GetSelectedComponent(count);
	if (count) 
	{
		numberDeletedItems = count;
		ArrayDeleted = new Component * [numberDeletedItems];
		for(int i = 0;i<count;i++)
			ArrayDeleted[i] = SelectedArr[i];
		for (int i = 0;i < count;i++)
		{
			pManager->RemoveComponent(&SelectedArr[i]);
			pManager->setDelArray(ArrayDeleted, numberDeletedItems);
		}
		pManager->setValidityofAction(true);
	}
	else {
		Component** c1;
		if (pA == NULL)
		{
			ReadActionParameters();
			c1 = pManager->getComponent(x1, y1);
		}
		else
		{
			c1 = &pA;
		}
		if (c1 != NULL)
		{
			pManager->RemoveComponent(c1);
			pManager->setDelArray(ArrayDeleted, numberDeletedItems);
			pManager->setValidityofAction(true);
		}
		else
		{
			pOut->PrintMsg("No pressed item! To try again press on Delete.");
			pManager->setValidityofAction(false);
		}
	}
	
	
}

void Delete::Undo()
{
	for(int i =0;i< numberDeletedItems;i++)
		pManager->AddComponent(ArrayDeleted[i]);


}


void Delete::Redo()
{
	for (int i = 0; i < numberDeletedItems; i++)
	{
		Action* dP =new Delete(pManager, ArrayDeleted[i]);
		dP->Execute();
	}
		
}