#include "Select.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{
	Comp = NULL;
	valid = false;
}

//Reads parameters required for action to execute
void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(GfxI.x1, GfxI.y1);
	Comp = pManager->getComponent(GfxI.x1, GfxI.y1);
	if (Comp != NULL)
		valid = true;
}

//Execute action (code depends on action type)
void Select::Execute()
{
	ReadActionParameters();
	if (valid)
	{
		if ((*Comp)->getSelected() == 0) {
			(*Comp)->setSelected(1);
		}
		else {
			(*Comp)->setSelected(0);
		}
		pManager->UpdateInterface();
	}
}


//To undo this action (code depends on action type)
void Select::Undo()
{}

//To redo this action (code depends on action type)
void Select::Redo()
{}
