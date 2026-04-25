#ifndef _ACTION_CPR_H
#define _ACTION_CPR_H

#include "Action.h"
#include "../Components/Component.h"

class ActionCPR : public Action
{
private:
    int x, y;
    Component* pComp;
public:
    ActionCPR(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif