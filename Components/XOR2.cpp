#include "XOR2.h"
#include "..\GUI\UI_Info.h"
#include <iostream>
#include <fstream>
using namespace std;

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{

	STATUS s1 = m_InputPins[0].getStatus();
	STATUS s2 = m_InputPins[1].getStatus();

	if (s1 == LOW && s2 == LOW)
		m_OutputPin.setStatus(LOW);
	else if (s1 == HIGH && s2 == HIGH)
		m_OutputPin.setStatus(LOW);
	else 
		m_OutputPin.setStatus(HIGH);
}


void XOR2::Draw(Output* pOut)
{
	pOut->DrawXOR2(m_GfxInfo, IsSelected());
	if (GetLabel() != "")
		pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}


int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR2::Save(ofstream& OutFile)
{
	OutFile << "XOR2 " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void XOR2::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}
