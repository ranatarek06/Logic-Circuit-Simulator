#include "BUF.h"
#include "..\GUI\UI_Info.h"
#include <iostream>
#include <fstream>
using namespace std;

BUF::BUF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUF::Operate()
{
	STATUS s1 = m_InputPins[0].getStatus();

	if (s1 == LOW)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


void BUF::Draw(Output* pOut)
{
	pOut->DrawBUF(m_GfxInfo, IsSelected());
	if (GetLabel() != "")
		pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}


int BUF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


int BUF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


void BUF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUF::Save(ofstream& OutFile)
{
	OutFile << "BUF " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void BUF::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}

