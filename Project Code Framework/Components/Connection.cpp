#include "Connection.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, Component* pS, Component* pD, int Pin, int IGI,int OGI) :Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	DestPin = Pin;
	InputGateIndex = IGI;
	OutputGateIndex = OGI;
}

//Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS = NULL, Component* pD = NULL, int Pin = 0) :Component(r_GfxInfo)
//{
//	SrcCmpnt = pS;
//	DstCmpnt = pD;	
//	DestPin = Pin;
//}

void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

//Component* Connection::GetSourceGate()
//{ return SrcCmpnt; }
//
//Component* Connection::GetDestinationGate()
//{ return DstCmpnt; }
//
//int Connection::GetDestPin()
//{ return DestPin; }
//
//int Connection::GetInputGateIndex()
//{ return InputGateIndex; }
//
//int Connection::GetOutputGateIndex()
//{ return OutputGateIndex; }

void Connection::Save(ofstream& file)
{
	file << OutputGateIndex +1 << " " << InputGateIndex +1 << " " << DestPin+1 << endl;
}

void Connection::Load(ifstream& file)
{

}