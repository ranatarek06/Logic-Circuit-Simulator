#ifndef _SWITCH_H
#define _SWITCH_H

#include "Component.h"
#include "OutputPin.h"

class SWITCH : public Component
{
private:
	OutputPin m_OutputPin; // drives the circuit
	STATUS m_State;        // current logical state of the switch

public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);

	// Component interface
	virtual void Operate();
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	// Expose pins so AddConnection / ApplicationManager can access them
	virtual OutputPin* GetOutputPin() override;
	virtual InputPin* GetInputPin(int n) override;

	virtual void SetOutputPinStatus(int s) override;
	virtual void Propagate(int s) override;

	// Convenience for UI: toggle the switch state
	void Toggle();
	void SetStatus(STATUS s);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);

	virtual Component* Clone() const override {
		return new SWITCH(*this);
	}
};

#endif