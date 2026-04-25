#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration

class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	// NEW: Track connection status
	bool m_IsConnected;

public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	
	void setConnected(bool status) { m_IsConnected = status; }
	bool isConnected() const { return m_IsConnected; }
};

#endif