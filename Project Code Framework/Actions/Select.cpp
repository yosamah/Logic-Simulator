#include <iostream>
using namespace std;
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "Select.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{
}

//Reads parameters required for action to execute
void Select::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get a Pointer to the Input / Output Interfaces
	pIn->GetPointClicked(x1, y1);

}

//Execute action (code depends on action type)
void Select::Execute()
{
	ReadActionParameters();
	Component** pComponent = pManager->getComponent(x1, y1);
	Component* pComp = (pComponent == NULL) ? NULL : *pComponent;
	if (pComp != NULL) {
		if ((pComp)->getSelected() == 0) {
			(pComp)->setSelected(1);
			
		}
		else {
			(pComp)->setSelected(0);
			
		}
		pManager->setValidityofAction(true);
		pManager->UpdateInterface();
	}
	else
		pManager->setValidityofAction(false);
}

//To undo this action (code depends on action type)
void Select::Undo()
{
	pManager->addSelecCompStack();
}

//To redo this action (code depends on action type)
void Select::Redo()
{
	pManager->remSelecCompStack();
}

