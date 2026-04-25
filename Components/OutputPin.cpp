#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

// Copy Constructor
OutputPin::OutputPin(const OutputPin& r_Pin)
{
	m_Conn = 0; // Reset connections for the copy
	m_FanOut = r_Pin.m_FanOut;
	for (int i = 0; i < MAX_CONNS; i++)
		m_Connections[i] = nullptr;
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}

bool OutputPin::Disconnect(Connection* r_Conn)
{
	for (int i = 0; i < m_Conn; i++)
	{
		if (m_Connections[i] == r_Conn)
		{
			// shift remaining connections left
			for (int j = i; j < m_Conn - 1; j++)
			{
				m_Connections[j] = m_Connections[j + 1];
			}

			m_Connections[m_Conn - 1] = NULL; // optional cleanup
			m_Conn--;
			return true;
		}
	}

	return false; // connection not found
}