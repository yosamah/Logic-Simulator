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
	//Boolean variable to check the validity of the connection.
	bool valid = true;
	//Output pointer to print validty message to the user.
	Output* pOut = pManager->GetOutput();
	//Get two points of the connection.
	ReadActionParameters();
	//To check the clicked component of the input gate.
	Component** comp1 = pManager->getComponent(GInfo.x2, GInfo.y2);
	// To display the accurate message.
	int messageNumber = 0;
	//If the output gate is invalid we will need to reset the status of the input pin. 
	int numberOfInputPin = -1;

	if (comp1 != NULL)
	{
		messageNumber = -1;
		int pinCount = (*comp1)->getNoOfInPins();
		//Checking switch gate. 
		if (pinCount != -1)
		{
			//Return the number of the pin pressed according to the pressed margin.
			int pinNumber = (*comp1)->checkMargin(GInfo.y2, pinCount);
			numberOfInputPin = pinNumber;
			//Check the status of the pin.
			int pinStatus = (*comp1)->GetInputPinStatus(pinNumber + 1);
			if (pinStatus == LOW)
			{
				//Set pDstPin.
				pDstPin = (*comp1)->getInputPin(pinNumber);
				//Set x, y coordinates of the pin pressed.
				GInfo.x2 = (*comp1)->getInPinLocationX(pinNumber);
				GInfo.y2 = (*comp1)->getInPinLocationY(pinNumber);
				(*comp1)->setXConnection(GInfo.x2);
				(*comp1)->setYConnection(GInfo.y2);
			}
			else
			{
				valid = false;
				messageNumber = 1;
			}

			
		}
		else
		{
			valid = false;
			messageNumber = 2;
		}
			
	}
	else
	{
		valid = false;
	}
	if (messageNumber == 0)
		pOut->PrintMsg("No input gate pressed!");
	else if (messageNumber == 1)
		pOut->PrintMsg("This pin has connection already! To reconnect press on connection.");
	else if (messageNumber == 2)
		pOut->PrintMsg("Swich has no input pins!");
		
		
	//Reseting the message number.
	messageNumber = 0;

	Component** comp2 = pManager->getComponent(GInfo.x1, GInfo.y1);
	//Check if the clicked points are on the same gate.
	if (comp1 != comp2)
	{
		messageNumber = -1;
		if (comp2 != NULL)
		{
			messageNumber = -2;
			int pinStatus = (*comp2)->GetOutPinStatus();
			//Return -1 for LED.
			if (pinStatus != -1)
			{
				if (pinStatus == LOW)
				{
					//Set pSrcPin.
					pSrcPin = (*comp2)->getOutputPin();

				}

				GInfo.x1 = (*comp2)->getOutPinLocationX();
				GInfo.y1 = (*comp2)->getOutPinLocationY();
				(*comp2)->setXOutConnection(GInfo.x1);
				(*comp2)->setYOutConnection(GInfo.y1);
			}
			else
			{
				messageNumber = 1;
				valid = false;
			}


		}
		else
		{
			messageNumber = 2;
			valid = false;
		}
	}
	else
	{
		valid = false;
	}
	if (messageNumber == 0)
		pOut->PrintMsg("You can't take input and output from the same gate!");
	else if (messageNumber == 1)
		pOut->PrintMsg("LED has no output pins!");
	else if (messageNumber == 2)
		pOut->PrintMsg("No Output gate pressed!");

		
	
	

	//Gfx info to be used to construct the AND2 gate
	if (valid)
	{
		Connection* pA = new Connection(GInfo, pSrcPin, pDstPin);
		if (comp2 != NULL && comp1 != NULL)
		{
			//Check the number of pins connected to the pressed output gate.
			int fanoutValidity = (*comp2)->ConnectToOut(pA);
			if (fanoutValidity)
			{
				pManager->AddComponent(pA);
				//Set this pin High.
				(*comp1)->setInputPinStatus(numberOfInputPin + 1, HIGH);
			}
				
			else
			{
				pOut->PrintMsg("This Output pin has max number of connections! To reconnect press on connection.");
			}
				
		}
		
	}
	
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

