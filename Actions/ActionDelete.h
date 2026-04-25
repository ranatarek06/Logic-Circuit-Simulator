#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class ActionDelete : public Action
{
public:
	ActionDelete(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
