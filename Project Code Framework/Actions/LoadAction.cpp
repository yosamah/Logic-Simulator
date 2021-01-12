#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
	valid = false;
}

//Reads parameters required for action to execute
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	file.open("Info.txt");

	if (file.is_open())
	{
		string Check = pIn->GetSrting(pOut, "All unsaved data will be removed. Do you want to continue (y/n):");
		if (Check == "y")
			valid = true;
		else
			pOut->PrintMsg("File not loaded!");
	}
	else
	{
		pOut->PrintMsg("File not found!");
	}
	pManager->setValidityofAction(false);
}

//Execute action (code depends on action type)
void LoadAction::Execute()
{
	ReadActionParameters();
	if (valid)
		pManager->Load(file);
}

//To undo this action (code depends on action type)
void LoadAction::Undo()
{}

//To redo this action (code depends on action type)
void LoadAction::Redo()
{}
