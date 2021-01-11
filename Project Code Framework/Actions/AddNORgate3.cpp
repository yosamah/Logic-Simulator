#include "AddNORgate3.h"
#include "..\ApplicationManager.h"
#include "Delete.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pA = new NOR3(GInfo, AND2_FANOUT);

	if (pA->InDrawingArea(Cx, Cy))
	{
		pManager->AddComponent(pA);
		pManager->setValidityofAction(true);
	}
	else
	{
		pManager->setValidityofAction(false);
	}

}

void AddNORgate3::Undo()
{
	Action* p = new Delete(pManager, pA);
	p->Execute();
}

void AddNORgate3::Redo()
{
	pManager->AddComponent(pA);
}

