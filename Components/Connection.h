#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);

	virtual void Operate() override;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) override;	//for each component to Draw itself
	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();


	virtual int GetOutPinStatus() override;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) override;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) override;	//set status of Inputpin # n, to be used by connection class.


	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	
	virtual Component* Clone() const override { return new Connection(*this); }

	~Connection();
};
