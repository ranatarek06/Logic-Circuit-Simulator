#pragma once
#ifndef _LED_H
#define _LED_H

#include "Component.h"
#include "InputPin.h"

class LED : public Component
{
private:
	InputPin m_InputPin; // LED has a single input pin
	STATUS m_State;      // current logical state shown by the LED

public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	LED(const LED& r_LED); // Copy Ctor

	// Component interface
	virtual void Operate() override;
	// Implement standard Draw so ApplicationManager calls work
	virtual void Draw(Output* pOut) override;
	// helper kept if you want direct call-site
	void DrawLED(Output* pOut);

	// LED has no output pin
	virtual int GetOutPinStatus() override;

	// expose input pin through Component API (0-based)
	virtual int GetInputPinStatus(int n) override;
	virtual void setInputPinStatus(int n, STATUS s) override;
	// allow AddConnection to get a pointer to the input pin
	virtual InputPin* GetInputPin(int n) override;

	virtual int GetInputPinCount() const override { return 1; }
	virtual bool AllInputPinsConnected() const override;
	virtual void SetOutputPinStatus(int s) override;
	virtual void Propagate(int s) override;

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	
	virtual Component* Clone() const override {
		return new LED(*this);
	}
};

#endif

