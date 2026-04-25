#pragma once
#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H

#include "Action.h"
#include <fstream>

class ActionLoad : public Action
{
public:
    ActionLoad(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() override {}
    virtual void Undo() override {}
    virtual void Redo() override {}
};

#endif