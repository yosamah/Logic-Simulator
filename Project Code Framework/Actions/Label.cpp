#include "Label.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"


Label::Label(ApplicationManager* pApp):Action(pApp)	//constructor
{

}
void Label::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Click on a component to label: ");
	pIn->GetPointClicked(x1, y1);

	pOut->ClearStatusBar();
}

void Label::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	pOut->PrintMsg("Click on a component: ");
	comp = pManager->getComponent(x1, y1);
	oldLabel = (*comp)->GetLabel();
	if (comp != NULL)
	{
		string l = pIn->GetSrting(pOut, "", "");
		(*comp)->SetLabel(l);
		newLabel = (*comp)->GetLabel();
		pOut->ClearStatusBar();

	}
	else
	{
		newLabel = " ";
		pOut->PrintMsg("No Clicked Component!");
	}
}
void Label::Undo()
{
	(*comp)->SetLabel(oldLabel);
}
void Label::Redo()
{
	(*comp)->SetLabel(newLabel);
}
