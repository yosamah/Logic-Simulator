#include "AddINVERTER.h"
#include "..\ApplicationManager.h"
#include "Delete.h"

AddINVERTER::AddINVERTER(ApplicationManager* pApp) :Action(pApp)
{
}


AddINVERTER::~AddINVERTER(void)
{
}

void AddINVERTER::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Drawing INVERTER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINVERTER::Execute()
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
	pA = new INVERTER(GInfo, AND2_FANOUT);

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

void AddINVERTER::Undo()
{
	Action* p = new Delete(pManager, pA);
	p->Execute();

}

void AddINVERTER::Redo()
{
	pManager->AddComponent(pA);
}

