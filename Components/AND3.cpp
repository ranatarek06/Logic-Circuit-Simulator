#include "AND3.h"
#include "..\GUI\UI_Info.h"
#include <iostream>
#include <fstream>
using namespace std;

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{

	STATUS s1 = m_InputPins[0].getStatus();
	STATUS s2 = m_InputPins[1].getStatus();
	STATUS s3 = m_InputPins[2].getStatus();

	if (s1 == HIGH && s2 == HIGH && s3 == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


void AND3::Draw(Output* pOut)
{
	pOut->DrawAND3(m_GfxInfo, IsSelected());
	if (GetLabel() != "")
		pOut->DrawString(m_GfxInfo.x1, m_GfxInfo.y1 - 20, GetLabel());
}


int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}


void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND3::Save(ofstream& OutFile)
{
	OutFile << "AND3 " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void AND3::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;
	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}
