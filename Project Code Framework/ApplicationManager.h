#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include<stack>

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


	Component* CopyComp; //pointer to the copied component
	
	bool actionValid;
	/*Component** ArrayDeleted;
	int countDelArray;*/
	MODE PrevMode;
	MODE CurrMode;


	stack<Action*> stackOfActionsList;
	stack<Action*> stackOfActionsUndo;

	stack<Component*>ArrayDelUndo;
	stack<Component*>ArrayDelRedo;


	stack<Component*>ArrayEditUndo;
	stack<Component*>ArrayEditRedo;

	stack<Component*>ArraySelUndo;
	stack<Component*>ArraySelRedo;



public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	void setValidityofAction(bool valid);
	//void setDelArray(Component**& delArray, int& count);

	void RemoveConnection(Component** c1);
	
	//string getString();
	int getGateNumber(Component* comp);

	void addDelCompStack(int count);
	void remDelCompStack( int count);
	void addEditCompStack(Component*);
	void addSelecCompStack();
	void remSelecCompStack();

	Component** getComponent(int x, int y);

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	Component* GetIDGate(int ID);

	int RemoveComponent(Component** c1);
	//Adds a new component to the list of components
	void AddComponent(Component* pComp,bool IsLoad = false);
	void Save(ofstream& file);
	void Load(ifstream& file);
	
	void SetCopiedComponent(Component *Comp);  //Setters and getters for the copied component
	Component* GetCopiedComponent();
	Component** GetSelectedComponent(int& count);
	//Selects a component in the list of components

	void CheckSimulation();

	//destructor
	~ApplicationManager();
};

#endif