#include "Paste.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
	Comp = NULL;
}

//Reads parameters required for action to execute
void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Comp = pManager->GetCopiedComponent();
	if (Comp == NULL)
		pOut->PrintMsg("There is no copied to gate to paste!");

}

//Execute action (code depends on action type)
void Paste::Execute()
{
	ReadActionParameters();
	Component* c;
	//c = dynamic_cast<Connection*>(*Comp);

	if (dynamic_cast<AND2*>(Comp))
	{
		Act = new AddANDgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<OR2*>(Comp))
	{
		Act = new AddORgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<NAND2*>(Comp))
	{
		Act = new AddNANDgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<NOR2*>(Comp))
	{
		Act = new AddNORgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<XOR2*>(Comp))
	{
		Act = new AddXORgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<XNOR2*>(Comp))
	{
		Act = new AddXNORgate2(pManager);
		Act->Execute();
	}
	if (dynamic_cast<AND3*>(Comp))
	{
		Act = new AddANDgate3(pManager);
		Act->Execute();
	}
	if (dynamic_cast<NOR3*>(Comp))
	{
		Act = new AddNORgate3(pManager);
		Act->Execute();
	}
	if (dynamic_cast<XOR3*>(Comp))
	{
		Act = new AddXORgate3(pManager);
		Act->Execute();
	}
	if (dynamic_cast<BUFFER*>(Comp))
	{
		Act = new AddBUFFER(pManager);
		Act->Execute();
	}
	if (dynamic_cast<INVERTER*>(Comp))
	{
		Act = new AddINVERTER(pManager);
		Act->Execute();
	}
	if (dynamic_cast<LED*>(Comp))
	{
		Act = new AddLED(pManager);
		Act->Execute();
	}
	if (dynamic_cast<SWITCH*>(Comp))
	{
		Act = new AddSWITCH(pManager);
		Act->Execute();
	}

}

//To undo this action (code depends on action type)
void Paste::Undo()
{}

//To redo this action (code depends on action type)
void Paste::Redo()
{}
