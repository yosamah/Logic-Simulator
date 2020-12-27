#include "AddConnection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-InputConnection: Click to add the connection");

	//Wait for User Input
	pIn->GetPointClicked(GInfo.x1, GInfo.y1);
	pIn->GetPointClicked(GInfo.x2, GInfo.y2);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get two points of the connection.
	
	ReadActionParameters();



	//Gfx info to be used to construct the AND2 gate

	Connection* pA = new Connection(GInfo, pSrcPin, pDstPin);
	pManager->AddComponent(pA);
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

