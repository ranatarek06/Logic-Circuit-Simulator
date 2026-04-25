#include "INV.h"
#include "..\GUI\UI_Info.h"
#include <iostream>
#include <fstream>
using namespace std;

INV::INV(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	STATUS s1 = m_InputPins[0].getStatus();

	if (s1 == LOW)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


void INV::Draw(Output* pOut)
{
	pOut->DrawINV(m_GfxInfo, IsSelected());
	if (GetLabel() != "")
		pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}


int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void INV::Save(ofstream& OutFile)
{
	OutFile << "INV " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void INV::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}
