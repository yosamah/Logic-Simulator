#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
	Loaded = false;
}
AddLED::AddLED(ApplicationManager* pApp, GraphicsInfo* G) : Action(pApp)
{
	if (G != NULL)
		Loaded = true;
	LoadC.x1 = G->x1;
	LoadC.y1 = G->y1;
}
AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Drawing LED Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
{
	if (!Loaded)
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
		LED* pA = new LED(GInfo, AND2_FANOUT);

		if (pA->InDrawingArea(Cx, Cy))
			pManager->AddComponent(pA);
	}
	else
	{
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

		GInfo.x1 = LoadC.x1 - Len / 2;
		GInfo.x2 = LoadC.x1 + Len / 2;
		GInfo.y1 = LoadC.y1 - Wdth / 2;
		GInfo.y2 = LoadC.y1 + Wdth / 2;
		LED* pA = new LED(GInfo, AND2_FANOUT);

		if (pA->InDrawingArea(LoadC.x1, LoadC.y1))
			pManager->AddComponent(pA);
	}
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}

