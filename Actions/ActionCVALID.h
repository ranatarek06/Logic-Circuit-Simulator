#ifndef ACTION_CVALID_H
#define ACTION_CVALID_H

#include "Action.h"

class ActionCVALID : public Action
{
public:
    ActionCVALID(ApplicationManager* pApp);
    virtual void Execute();
    virtual void ReadActionParameters() {}
    virtual void Undo() override {}
    virtual void Redo() override {}
};

#endif