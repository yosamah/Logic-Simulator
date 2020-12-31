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
	pOut->PrintMsg("Connection: Click to add the connection");

	//Wait for User Input
	pIn->GetPointClicked(GInfo.x1, GInfo.y1);
	pIn->GetPointClicked(GInfo.x2, GInfo.y2);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	bool v = false;
	/*Get two points of the connection.*/
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Component** comp1 = pManager->getComponent(GInfo.x2, GInfo.y2);
	
	if (comp1 != NULL)
	{
		int j = (*comp1)->getNoOfInPins();
		if (j != 0)
		{
			int n = (*comp1)->checkMargin(GInfo.y2, j);
			int u = (*comp1)->GetInputPinStatus(n + 1);
			if (u == LOW)
			{
				pDstPin = (*comp1)->getInputPin(u);
				(*comp1)->setInputPinStatus(n + 1, HIGH);
			}
			else
			{
				v = true;
				pOut->PrintMsg("This pin has connection already! To reconnect press on connection.");
			}

			GInfo.x2 = (*comp1)->getInPinLocationX(n);
			GInfo.y2 = (*comp1)->getInPinLocationY(n);
			(*comp1)->setXConnection(GInfo.x2);
			(*comp1)->setYConnection(GInfo.y2);
		}
		else
		{
			pOut->PrintMsg("Swich has no input pins!");
			v = true;

		}
			
	}
	else
	{
		pOut->PrintMsg("No input gate pressed!");
	}
		
		

	Component** comp2 = pManager->getComponent(GInfo.x1, GInfo.y1);
	if (comp2 != NULL)
	{
		int u = (*comp2)->GetOutPinStatus();
		if (u != -1)
		{
			if (u == LOW)
			{
				pSrcPin = (*comp2)->getOutputPin();

			}

			GInfo.x1 = (*comp2)->getOutPinLocationX();
			GInfo.y1 = (*comp2)->getOutPinLocationY();
			(*comp2)->setXOutConnection(GInfo.x1);
			(*comp2)->setYOutConnection(GInfo.y1);
		}
		else
		{
			pOut->PrintMsg("LED has no output pins!");
			v = true;
		}
			

	}
	else
	{
		pOut->PrintMsg("No Output gate pressed!");
		v = true;
	}
	

	//Gfx info to be used to construct the AND2 gate
	if (!v)
	{
		Connection* pA = new Connection(GInfo, pSrcPin, pDstPin);
		if (comp2 != NULL)
		{
			int m = (*comp2)->ConnectToOut(pA);
			if (m)
				pManager->AddComponent(pA);
			else
				pOut->PrintMsg("This Output pin has max number of connections! To reconnect press on connection.");
		}
		
	}
	
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

