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
	Component** comp = pManager->getComponent(x1, y1);
	if (comp != NULL)
	{
		Component* testConnection = dynamic_cast<Connection*>(*comp);
		if (!testConnection)
		{
			string l = pIn->GetSrting(pOut, "", "");
			(*comp)->SetLabel(l);
			pOut->ClearStatusBar();
		}
		else
		{
			string testLabel = pIn->GetSrting(pOut, "Do you want edit a label? (y/n)");
			if (testLabel == "y")
			{
				string l = pIn->GetSrting(pOut, "", "");
				(*comp)->SetLabel(l);
				pOut->ClearStatusBar();
			}
			else
			{
				pOut->PrintMsg("Choose whether source gate or destination gate!");
				pIn->GetPointClicked(x1, y1);
				Component* comp2 = (*comp)->GetSourceGate();
				Component* comp1 = (*comp)->GetDestinationGate();
				bool checkSourceGate = comp1->drawArea(x1, y1);
				bool checkDestGate = comp2->drawArea(x1, y1);
				if (checkSourceGate)
				{
					pOut->PrintMsg("Click on the new source pin.");
					pIn->GetPointClicked(x1, y1);
					Component** newComp = pManager->getComponent(x1, y1);
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
					Component** newComp = pManager->getComponent(x1, y1);
					if (newComp != NULL)
					{
						int numberPins = (*newComp)->getNoOfInPins();
						int pinN = (*newComp)->checkMargin(y1, numberPins);
						int checkChange = (*comp)->changeDst(*newComp, pinN);
						if (checkChange == 0)
							pOut->PrintMsg("The pin has connection already! ");
						else if (checkChange == -1)
							pOut->PrintMsg("You didn't press on a gate! ");
						else
						{
							int oldPin = (*comp)->GetDPin();
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

}
void Edit::Redo()
{

}