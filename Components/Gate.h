#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate(int r_Inputs, int r_FanOut);
	
	// Copy constructor for deep copy (Inline to prevent linker errors)
	Gate(const Gate& r_Gate) : Component(r_Gate.GetLocation()), m_OutputPin(r_Gate.m_OutputPin)
	{
		m_Inputs = r_Gate.m_Inputs;
		m_InputPins = new InputPin[m_Inputs]; // Allocate NEW pins
		
		// Initialize new pins (they start disconnected)
		for (int i = 0; i < m_Inputs; i++)
		{
			m_InputPins[i].setComponent(this); // Associate with THIS new gate
		}
	}

	virtual ~Gate()
	{
		if (m_InputPins)
			delete[] m_InputPins;
	}
	
	// Simulation Support
	virtual int GetInputPinCount() const override { return m_Inputs; }
	virtual bool AllInputPinsConnected() const override;
	virtual void SetOutputPinStatus(int s) override;
	virtual void Propagate(int s) override;

	virtual OutputPin* GetOutputPin() override { return &m_OutputPin; }
	virtual InputPin* GetInputPin(int n) override;

	// Gate remains abstract regarding Clone unless we implement it here using template or specific derived call
	// For now, let derived classes implement Clone
	virtual Component* Clone() const = 0; 
};

#endif
