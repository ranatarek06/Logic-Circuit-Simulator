#include "..\GUI\UI_Info.h"
#include "AND2.h"
#include <iostream>
#include <fstream>
using namespace std;

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here

		STATUS s1 = m_InputPins[0].getStatus();
		STATUS s2 = m_InputPins[1].getStatus();

		if (s1 == HIGH && s2 == HIGH)
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);

}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	// Draw the gate as not-selected (prevent automatic red selection while keeping actual state)
	pOut->DrawAND2(m_GfxInfo, IsSelected());

	// Draw the label (if any) approximately centered above the gate
	if (!GetLabel().empty())
	{
		int centerX = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2;
		int labelY  = m_GfxInfo.y1 - 20;
		pOut->DrawString(centerX, labelY, GetLabel());
	}
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}


void AND2::Save(ofstream& OutFile)
{
	OutFile << "AND2 "
		<< m_GfxInfo.x1 << " "
		<< m_GfxInfo.y1
		<< endl;
}

void AND2::Load(ifstream& InFile)
{
	InFile >> m_GfxInfo.x1 >> m_GfxInfo.y1;

	m_GfxInfo.x2 = m_GfxInfo.x1 + UI.GateWidth;
	m_GfxInfo.y2 = m_GfxInfo.y1 + UI.GateHeight;
}

