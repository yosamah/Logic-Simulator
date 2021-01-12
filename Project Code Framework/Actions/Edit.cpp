#include "Edit.h"
#include <iostream>
using namespace std;
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"




Edit::Edit(ApplicationManager* pApp): Action(pApp)
{
}

void Edit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Click on a component to edit: ");
	pIn->GetPointClicked(x1, y1);

	pOut->ClearStatusBar();
}
void Edit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	comp = pManager->getComponent(x1, y1);
	if (comp != NULL)
	{
		testConnection = dynamic_cast<Connection*>(*comp);
		if (!testConnection)
		{
			oldLabel = (*comp)->GetLabel();
			newLabel = pIn->GetSrting(pOut, "", "");
			(*comp)->SetLabel(newLabel);
			pOut->ClearStatusBar();
			
		}
		else
		{
			testLabel = pIn->GetSrting(pOut, "Do you want edit a label? (y/n)");
			if (testLabel == "y")
			{
				oldLabel = (*comp)->GetLabel();
				newLabel = pIn->GetSrting(pOut, "", "");
				(*comp)->SetLabel(newLabel);
				pOut->ClearStatusBar();
			}
			else
			{
				pOut->PrintMsg("Choose whether source gate or destination gate!");
				pIn->GetPointClicked(x1, y1);
				comp2 = (*comp)->GetSourceGate();
				comp1 = (*comp)->GetDestinationGate();
				checkSourceGate = comp1->drawArea(x1, y1);
				checkDestGate = comp2->drawArea(x1, y1);
				if (checkSourceGate)
				{
					pOut->PrintMsg("Click on the new source pin.");
					pIn->GetPointClicked(x1, y1);
					pOut->ClearStatusBar();
					newComp = pManager->getComponent(x1, y1);
					if (newComp != NULL)
					{
						int checkChange = (*comp)->changeSrc(*newComp);
						if (checkChange == 0)
							pOut->PrintMsg("The source gate has max number of pins! ");
						else if (checkChange == -1)
							pOut->PrintMsg("You didn't press on a gate! ");
						else
							(comp1)->removeConToOut((Connection*)*comp);
					}
					else
						pOut->PrintMsg("You didn't press on a gate! ");
					
				}
				else if (checkDestGate)
				{
					pOut->PrintMsg("Click on the new destenation pin.");
					pIn->GetPointClicked(x1, y1);
					pOut->ClearStatusBar();
					newComp = pManager->getComponent(x1, y1);
					if (newComp != NULL)
					{
						int numberPins = (*newComp)->getNoOfInPins();
						pinN = (*newComp)->checkMargin(y1, numberPins);
						oldPin = (*comp)->GetDPin();
						int checkChange = (*comp)->changeDst(*newComp, pinN);
						if (checkChange == 0)
							pOut->PrintMsg("The pin has connection already! ");
						else if (checkChange == -1)
							pOut->PrintMsg("You didn't press on a gate! ");
						else
						{
							(comp2)->setInputPinStatus(oldPin+1, LOW);
						}
							

					}
					else
						pOut->PrintMsg("You didn't press on a gate! ");
					
				}
				else
				{
					pOut->PrintMsg("This is neither source gate nor destintation gate.");
				}
			}
		}
	}
}
void Edit::Undo()
{
	if (!testConnection)
	{
		(*comp)->SetLabel(oldLabel);
	}
	else if (testLabel == "y")
	{
		(*comp)->SetLabel(oldLabel);
	}
	else if (checkSourceGate)
	{
	 (*comp)->changeSrc(comp1);
	 (*newComp)->removeConToOut((Connection*)*comp);
	}
	else if (checkDestGate)
	{
		(*comp)->changeDst(comp2, oldPin);
		(*newComp)->setInputPinStatus(pinN + 1, LOW);

	}
}
void Edit::Redo()
{
	if (!testConnection)
	{
		(*comp)->SetLabel(newLabel);
	}
	else if (testLabel == "y")
	{
		(*comp)->SetLabel(newLabel);
	}
	else if (checkSourceGate)
	{
		(*comp)->changeSrc(*newComp);
		(comp1)->removeConToOut((Connection*)*comp);
	}
	else if (checkDestGate)
	{
		(*comp)->changeDst(*newComp, pinN);
		(comp2)->setInputPinStatus(oldPin + 1, LOW);

	}
}