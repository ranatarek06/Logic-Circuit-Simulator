#pragma once
#include "Gate.h"
#ifndef _XOR2_H
#define _XOR2_H

class XOR2 : public Gate
{
public:
	XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new XOR2(*this); }
};

#endif
