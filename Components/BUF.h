#pragma once
#include "Gate.h"
#ifndef _BUF_H
#define _BUF_H

class BUF : public Gate
{
public:
	BUF(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new BUF(*this); }
};

#endif
