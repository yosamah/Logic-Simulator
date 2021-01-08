#include "Paste.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{}

//Reads parameters required for action to execute
void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	*Comp = pManager->GetCopiedComponent();
	if (*Comp == NULL)
		pOut->PrintMsg("There is no copied to gate to paste!");

}

//Execute action (code depends on action type)
void Paste::Execute()
{

}

//To undo this action (code depends on action type)
void Paste::Undo()
{}

//To redo this action (code depends on action type)
void Paste::Redo()
{}
