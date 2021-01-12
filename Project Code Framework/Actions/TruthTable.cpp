#include "TruthTable.h"
#include <queue>
#include <iomanip>
#include <string> 

TruthTable::TruthTable(ApplicationManager* pApp) :Action(pApp)
{
	InCnt = 0;
	OutCnt = 0;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Truth table created.");
	truth.open("TruthTable.txt");
	truth.clear();
}

void TruthTable::ReadActionParameters()
{
	Switches = pManager->GetSwitch(InCnt);
	Leds = pManager->GetLed(OutCnt);
	rows = (int)pow(2, InCnt);
	cols = InCnt + OutCnt;
	original = new int[InCnt];
	for (int i = 0;i < InCnt;i++) {
		original[i] = Switches[i]->GetOutPinStatus();
	}
}
void TruthTable::Execute()
{
	//Setting Input Permutations
	ReadActionParameters();
	perm = new int* [rows];
	for (int i = 0;i < rows;i++) {
		perm[i] = new int[cols];
	}
	int inc(pow(2, InCnt - 1));
	int curr(0);
	for (int i = 0;i < InCnt;i++) {
		for (int j = 0;j < rows;) {
			for (int k = 0;k < inc;k++,j++) {
				perm[j][i] = 0;
			}
			for (int k = 0;k < inc;k++,j++) {
				perm[j][i] = 1;
			}
		}
		inc /= 2;
	}

	//Calculating Output
	queue <Component*> qu;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < InCnt;j++) {
			Switches[j]->getOutputPin()->setSIMStatus((STATUS)perm[i][j]);
			qu.push(Switches[j]);
		}

		while (!qu.empty()) {
			qu.front()->Operate();
			Component* c = dynamic_cast<Gate*>(qu.front());
			if(c) {
				Component* d = dynamic_cast<LED*>(qu.front()); 
				if (d) continue;
				int num = 0;
				num = c->getOutputPin()->getmConn();
				for (int z = 0;z < num;z++) {
					if(c->getOutputPin()->getConn(z)!=NULL)
					qu.push(c->getOutputPin()->getConn(z));
				}
			}
			else {
				if(qu.front()->GetDestinationGate()!=NULL)
				qu.push((Connection*)(qu.front()) ->GetDestinationGate());
			}
			qu.pop();
		}
		for (int k = 0;k < OutCnt;k++) {
			perm[i][k + InCnt] = (Leds[k])->getInputPin(1)->getSIMStatus();
		}
	}
	Output* pOut = pManager->GetOutput();

	//Returning to original
		for (int i = 0;i < InCnt;i++) {
			Switches[i]->getOutputPin()->setSIMStatus((STATUS)original[i]);
			qu.push(Switches[i]);
		}
		while (!qu.empty()) {
			qu.front()->Operate();
			int num = 0;
			if (qu.front()->getOutputPin() != NULL) {
				num = qu.front()->getOutputPin()->getmConn();
			}
			for (int j = 0;j < num;j++) {
				qu.push(qu.front()->getOutputPin()->getConn(j));
			}
			qu.pop();
		}
		Save();
}

void TruthTable::Save() {
	for (int i = 0;i < InCnt;i++) {
		string in = "Input_" + to_string(i+1);
		truth <<setw(20)<<in;
	}
	for (int i = 0;i < OutCnt;i++) {
		string in = "Output_" + to_string(i+1);
		truth << setw(20) << in;
	}
	truth << endl;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			truth << setw(20) << perm[i][j];
		}
		truth<<endl;
	}
	truth.close();
}