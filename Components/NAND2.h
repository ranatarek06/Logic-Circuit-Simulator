#include "Gate.h"
#ifndef _NAND2_H
#define _NAND2_H


class NAND2 : public Gate
{
public:
	NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	

	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);	

	virtual void setInputPinStatus(int n, STATUS s);	

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override { return new NAND2(*this); }
};

#endif