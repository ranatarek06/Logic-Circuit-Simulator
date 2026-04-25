#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
class InputPin;
class OutputPin;
//Base class for classes Gate, Switch, and LED.
class Component
{
	string m_Label;
protected:
	bool m_Selected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	// NEW: Simulation support
	virtual int GetInputPinCount() const { return 0; }
	virtual bool AllInputPinsConnected() const { return true; }
	virtual void SetOutputPinStatus(int s) {}
	virtual void Propagate(int s) {}

	GraphicsInfo GetGraphicsInfo() const { return m_GfxInfo; } //NEW
	virtual OutputPin* GetOutputPin() { return nullptr; } //NEW
	virtual InputPin* GetInputPin(int n) { return nullptr; } //NEW

	// Wrappers for compatibility
	GraphicsInfo GetLocation() const { return m_GfxInfo; }
	void GetLocation(int &x, int &y) { x = m_GfxInfo.x1; y = m_GfxInfo.y1; }
	int GetOutputPinStatus() { return GetOutPinStatus(); }



	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();

	// NEW: Serialization and Copy
	virtual void Save(ofstream& OutFile) = 0;
	virtual void Load(ifstream& InFile) = 0;
	virtual Component* Clone() const = 0;

	// NEW: Location management
	void SetLocation(int x, int y) {
		int w = m_GfxInfo.x2 - m_GfxInfo.x1;
		int h = m_GfxInfo.y2 - m_GfxInfo.y1;
		m_GfxInfo.x1 = x;
		m_GfxInfo.y1 = y;
		m_GfxInfo.x2 = x + w;
		m_GfxInfo.y2 = y + h;
	}

	// --- [ADDED] New Helper Functions ---

// Check if a point is inside this component (for clicking)
	virtual bool InsideArea(int x, int y)
	{
		return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
			y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
	}

	void SetSelected(bool s) { m_Selected = s; }
	bool IsSelected() const { return m_Selected; }

	void SetLabel(string label) { m_Label = label; }
	string GetLabel() const { return m_Label; }
};

#endif
