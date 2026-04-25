#pragma once
#include "Gate.h"
#ifndef _AND3_H
#define _AND3_H

class AND3 : public Gate
{
public:
	AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new AND3(*this); }
};

#endif
