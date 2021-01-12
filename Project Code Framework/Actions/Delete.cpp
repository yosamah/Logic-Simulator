#include "Delete.h"
#include <iostream>
using namespace std;
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"


Delete::Delete(ApplicationManager* pApp, Component* p):Action(pApp)
{
	pA = p;
	countDel = 0;
}
	
void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Press on any item to delete it!");
	pIn->GetPointClicked(x1, y1);

	pOut->ClearStatusBar();
}


void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	int count = 0;
	Component** SelectedArr = pManager->GetSelectedComponent(count);
	if (count) 
	{
		for (int i = 0;i < count;i++)
		{
			int number = pManager->RemoveComponent(&SelectedArr[i]);
			countDel  = countDel + number;

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
			int number = pManager->RemoveComponent(c1);
			countDel = countDel + number;
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
	pManager->remDelCompStack(countDel);
}


void Delete::Redo()
{
	pManager->addDelCompStack(countDel);
}