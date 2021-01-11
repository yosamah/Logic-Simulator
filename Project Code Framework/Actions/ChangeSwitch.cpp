#include "ChangeSwitch.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) : Action(pApp)
{
	Comp = NULL;
	Comp2 = NULL;
	valid = false;
}

//Reads parameters required for action to execute
void ChangeSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pIn->GetPointClicked(GfxI.x1, GfxI.y1);
	
	

	//Get the clicked component
	Comp = pManager->getComponent(GfxI.x1, GfxI.y1);
	if (Comp != NULL)
	{
		Component* C = dynamic_cast<SWITCH*>(*Comp); //maybe error used same variable
		if (C)
		{
			valid = true;
		}
		else
		{
			pOut->PrintMsg("Please click on a switch!");
			valid = false;
		}
	}

}

//Execute action (code depends on action type)
void ChangeSwitch::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (valid)
	{
		if ((*Comp)->getSelected() == 0)
		{
			(*Comp)->setSelected(true);
		}
		else {
			(*Comp)->setSelected(0);
		}
		//pManager->UpdateInterface();
	}
}

//To undo this action (code depends on action type)
void ChangeSwitch::Undo()
{}

//To redo this action (code depends on action type)
void ChangeSwitch::Redo()
{}
