#include "Cut.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
	Comp = NULL;
	valid = true;
}

//Reads parameters required for action to execute
void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->UpdateInterface();

	//Print Action Message
	pOut->PrintMsg("Select a gate to be cut!");
	//Wait for User Input
	pIn->GetPointClicked(GfxI.x1, GfxI.y1);

	//Get the clicked component
	Comp = pManager->getComponent(GfxI.x1, GfxI.y1);

	pOut->ClearStatusBar();

	//Check if the point clicked is on a gate or an empty space
	if (Comp == NULL)
	{
		pOut->PrintMsg("There is no selected gate to be cut!");
		valid = false;
	}
}

//Execute action (code depends on action type)
void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	if (valid)
	{
		pManager->SetCopiedComponent(*Comp);
		pManager->RemoveComponent(Comp);
		pOut->PrintMsg("Component Cut!");
	}
}

//To undo this action (code depends on action type)
void Cut::Undo()
{}

//To redo this action (code depends on action type)
void Cut::Redo()
{}