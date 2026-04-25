#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut):Component(r_GfxInfo), m_OutputPin(r_FanOut)
{
	m_State = LOW; // Default state
}

void SWITCH::Operate()
{
	// Switch state is set by user interaction, not calculation
	// Ensure output pin matches state
	m_OutputPin.setStatus(m_State);
}

void SWITCH::Draw(Output* pOut)
{
	pOut->DrawSwitch(m_GfxInfo, m_State == HIGH, m_Selected);
}

int SWITCH::GetOutPinStatus()
{
	return m_State;
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1; // Switch has no inputs
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
	// No inputs
}

OutputPin* SWITCH::GetOutputPin()
{
	return &m_OutputPin;
}

InputPin* SWITCH::GetInputPin(int n)
{
	return nullptr;
}

void SWITCH::Toggle()
{
	m_State = (m_State == LOW) ? HIGH : LOW;
}

void SWITCH::Save(ofstream& OutFile)
{
	// Implementation dependent
}

void SWITCH::Load(ifstream& InFile)
{
	// Implementation dependent
}

void SWITCH::SetOutputPinStatus(int s)
{
	m_State = (STATUS)s;
	m_OutputPin.setStatus(m_State);
}

void SWITCH::Propagate(int s)
{
	// No-op
}
