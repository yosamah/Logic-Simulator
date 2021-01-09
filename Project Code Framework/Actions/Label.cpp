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
	Component** c = pManager->getComponent(x1, y1);

	if (c != NULL)
	{
		string l = pIn->GetSrting(pOut, "", "");
		(*c)->SetLabel(l);
		pOut->ClearStatusBar();

	}
	else
	{
		pOut->PrintMsg("No Clicked Component!");
	}
}
void Label::Undo()
{

}
void Label::Redo()
{

}
