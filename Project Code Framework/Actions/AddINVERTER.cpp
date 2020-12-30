#include "AddINVERTER.h"
#include "..\ApplicationManager.h"

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

	GraphicsInfo GInfo; //Gfx info to be used to construct the INVERTER2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INVERTER* pA = new INVERTER(GInfo, AND2_FANOUT);
	if (pA->InDrawingArea(Cx, Cy))
		pManager->AddComponent(pA);
}

void AddINVERTER::Undo()
{}

void AddINVERTER::Redo()
{}

