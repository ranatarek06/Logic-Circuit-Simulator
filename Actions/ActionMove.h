#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"

class ActionMove : public Action
{
public:
    ActionMove(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};
