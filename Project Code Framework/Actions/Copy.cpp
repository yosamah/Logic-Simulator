#include "Copy.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{
	Comp = NULL;
	valid = true;
}

//Reads parameters required for action to execute
void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select a gate to be copied!");

	//Wait for User Input
	pIn->GetPointClicked(GfxI.x1, GfxI.y1);

	//Get the clicked component
	Comp = pManager->getComponent(GfxI.x1, GfxI.y1);

	pOut->ClearStatusBar();

	//Check if the point clicked is on a gate or an empty space
	if (Comp == NULL)
	{
		pOut->PrintMsg("There is no selected gate to be copied!");
		valid = false;
	}

	//Clear Status Bar
}

//Execute action (code depends on action type)
void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	if (valid)
	{
		pManager->SetCopiedComponent(*Comp);
		pOut->PrintMsg("Component copied!");
	}
}

//To undo this action (code depends on action type)
void Copy::Undo()
{}

//To redo this action (code depends on action type)
void Copy::Redo()
{}
