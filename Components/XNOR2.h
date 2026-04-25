#pragma once
#include "Gate.h"
#ifndef _XNOR2_H
#define _XNOR2_H

class XNOR2 : public Gate
{
public:
	XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new XNOR2(*this); }
};

#endif
