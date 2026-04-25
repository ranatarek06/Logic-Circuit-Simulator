#include "XNOR2.h"
#include "..\GUI\UI_Info.h"
#include <iostream>
#include <fstream>
using namespace std;

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{

	STATUS s1 = m_InputPins[0].getStatus();
	STATUS s2 = m_InputPins[1].getStatus();

	if (s1 == LOW && s2 == LOW)
		m_OutputPin.setStatus(HIGH);
	else if (s1 == HIGH && s2 == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


void XNOR2::Draw(Output* pOut)
{
	pOut->DrawXNOR2(m_GfxInfo, IsSelected());
	if (GetLabel() != "")
		pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}


int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XNOR2::Save(ofstream& OutFile)
{
	OutFile << "XNOR2 " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void XNOR2::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}
