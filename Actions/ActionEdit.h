#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class ActionEdit : public Action
{
public:
	ActionEdit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
