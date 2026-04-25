#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut):Component(r_GfxInfo)
{
	m_InputPin.setComponent(this);
}

// Copy Constructor
LED::LED(const LED& r_LED) : Component(r_LED.GetGraphicsInfo())
{
	m_InputPin.setComponent(this);
	m_InputPin.setConnected(false); // Reset connection status
	m_State = r_LED.m_State;
}

void LED::Operate()
{
	// LED reads its input pin
	// If High, it lights up
	// Implementation might vary, but Operate usually updates internal state from InputPin
	// Check InputPin status? 
	// Usually InputPin does NOT store status? 
	// InputPin gets status from Connection?
	// Connection::Operate pushes value to DstPin? (DstPin has no value storage in Pin.h? Pin.h has m_Status!)
	
	// So Connection sets InputPin m_Status.
	// LED reads InputPin m_Status.
	m_State = (STATUS)m_InputPin.getStatus();
}

void LED::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo, m_State == HIGH, m_Selected);
}

int LED::GetOutPinStatus()
{
	return -1; // No output
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}

InputPin* LED::GetInputPin(int n)
{
	return &m_InputPin;
}

void LED::Save(ofstream& OutFile)
{
	// To be implemented
}

void LED::Load(ifstream& InFile)
{
	// To be implemented
}

bool LED::AllInputPinsConnected() const
{
	return m_InputPin.isConnected();
}

void LED::SetOutputPinStatus(int s)
{
	// No output pin
}

void LED::Propagate(int s)
{
	// No output pin to propagate
}
