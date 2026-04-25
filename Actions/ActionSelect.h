#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
