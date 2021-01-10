#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}

//Reads parameters required for action to execute
void SaveAction::ReadActionParameters()
{}

//Execute action (code depends on action type)
void SaveAction::Execute()
{
	file.open("Info.txt");
	file.clear();
	pManager->Save(file);
}

//To undo this action (code depends on action type)
void SaveAction::Undo()
{}

//To redo this action (code depends on action type)
void SaveAction::Redo()
{}
