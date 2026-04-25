#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin, InputPin *pDstPin)
	: Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	// Register this connection with the source output pin so the pin's
	// connection list / fanout bookkeeping is kept in sync.
	if (SrcPin)
		SrcPin->ConnectTo(this);
}

void Connection::setSourcePin(OutputPin* p) {
	if (SrcPin && SrcPin != p) SrcPin->Disconnect(this);
	SrcPin = p;
	if (SrcPin) SrcPin->ConnectTo(this);
}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}

void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{
	return DstPin;
}

void Connection::Save(ofstream& OutFile)
{
	// Implementation dependent - needs pin/component IDs usually
}

void Connection::Load(ifstream& InFile)
{
	// Implementation dependent
}

void Connection::Operate()
{
	// Guard: don't dereference null pointers
	if (!SrcPin || !DstPin) return;
	// Propagate source status to destination
	DstPin->setStatus(SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()
{
	if (DstPin)
		return DstPin->getStatus();
	else
		return -1;
}

int Connection::GetInputPinStatus(int n)
{
	if (SrcPin)
		return SrcPin->getStatus();
	else
		return -1;
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	// Allow external code to set the source pin status (use with care).
	if (SrcPin) SrcPin->setStatus(s);
}

// (illustrative)
Connection::~Connection() {
	if (SrcPin) SrcPin->Disconnect(this); // implement Disconnect on OutputPin
}

