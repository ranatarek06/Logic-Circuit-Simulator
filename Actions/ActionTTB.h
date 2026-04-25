#ifndef ACTION_TTB_H
#define ACTION_TTB_H

#include "Action.h"

class ActionTTB : public Action
{
public:
    ActionTTB(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() override {}
    virtual void Undo() override {}
    virtual void Redo() override {}
};

#endif
