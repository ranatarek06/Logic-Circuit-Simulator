#ifndef _ACTION_EXIT_H
#define _ACTION_EXIT_H

#include "Action.h"

class ActionEXIT : public Action
{
public:
	ActionEXIT(ApplicationManager* pApp) : Action(pApp) {}
	virtual ~ActionEXIT() {}

	virtual void ReadActionParameters() override {} 
	virtual void Execute() override;
	virtual void Undo() override {}
	virtual void Redo() override {}
};

#endif