#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class ActionLabel : public Action
{
public:
	ActionLabel(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
