#include "Gate.h"
#ifndef _OR2_H
#define _OR2_H


class OR2: public Gate
{
public:
	OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//will calculate the output of the OR gate
	virtual void Draw(Output* pOut);	//this will draw the 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new OR2(*this); }
};

#endif

