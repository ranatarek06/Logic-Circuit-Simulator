#ifndef ACTION_SIMC_H
#define ACTION_SIMC_H

#include "Action.h"

class ActionSIMC : public Action
{
private:
    int clickX, clickY;
public:
    ActionSIMC(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() override {}
    virtual void Redo() override {}
};

#endif
