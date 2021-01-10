#include "ChangeSwitch.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) : Action(pApp)
{
	Comp = NULL;
	valid = false;
}

//Reads parameters required for action to execute
void ChangeSwitch::ReadActionParameters()
{
	pIn->GetPointClicked(GfxI.x1, GfxI.y1);

	//Get the clicked component
	Comp = pManager->getComponent(GfxI.x1, GfxI.y1);
	Comp = dynamic_cast<SWITCH*>(Comp); //maybe error used same variable
	if (Comp)
	{
		valid = true;
	}
	else
	{
		pOut->PrintMsg("Please click on a switch!");
		valid = false;
	}

}

//Execute action (code depends on action type)
void ChangeSwitch::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (valid)
	{
		if ((*Comp)->getActive() == 0) {
			(*Comp)->setActive(1);
			GateImage = "Images\\Gate\\SWITCH_Hi.jpg";
			pWind->DrawImage(GateImage, GfxI.x1, GfxI.y1, UI.AND2_Width, UI.AND2_Height);
		}
		else {
			(*Comp)->setActive(0);
		}
		UpdateInterface();
	}
}

//To undo this action (code depends on action type)
void ChangeSwitch::Undo()
{}

//To redo this action (code depends on action type)
void ChangeSwitch::Redo()
{}
