#include "Delete.h"
#include <iostream>
using namespace std;
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"


Delete::Delete(ApplicationManager* pApp):Action(pApp)
{

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
	ReadActionParameters();
	Component** c1 = pManager->getComponent(x1, y1);
	if (c1 != NULL)
	{
		pManager->RemoveComponent(c1);
	}
	else
	{
		pOut->PrintMsg("No pressed item! To try again press on Delete.");
	}
	
	
}

void Delete::Undo()
{

}


void Delete::Redo()
{

}