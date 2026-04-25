#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Action.h"
#include "..\Components\Connection.h"

class AddConnection : public Action
{
private:
	int x1, y1;   // First click (source component)
	int x2, y2;   // Second click (destination component)

public:
	AddConnection(ApplicationManager* pApp);

	// Reads parameters required for action to execute
	virtual void ReadActionParameters();

	// Execute action
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif

