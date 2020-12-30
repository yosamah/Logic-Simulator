#include "AddXORgate2.h"
#include "..\ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
	Loaded = false;
}
AddXORgate2::AddXORgate2(ApplicationManager* pApp, GraphicsInfo* G) : Action(pApp)
{
	if (G != NULL)
		Loaded = true;
	LoadC.x1 = G->x1;
	LoadC.y1 = G->y1;
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XOR Gate: Click to add the gate");

	//Wait fXOR User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXORgate2::Execute()
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
		XOR2* pA = new XOR2(GInfo, AND2_FANOUT);

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
		XOR2* pA = new XOR2(GInfo, AND2_FANOUT);

		if (pA->InDrawingArea(LoadC.x1, LoadC.y1))
			pManager->AddComponent(pA);
	}
}

void AddXORgate2::Undo()
{}

void AddXORgate2::Redo()
{}

