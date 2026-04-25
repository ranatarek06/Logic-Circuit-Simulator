#pragma once

#include "Action.h"
#include "../ApplicationManager.h"
#include <fstream>

class ActionSave : public Action
{
public:
    ActionSave(ApplicationManager* pApp);
    virtual void Execute() override;
    virtual void ReadActionParameters() override {}
    virtual void Undo() override {}
    virtual void Redo() override {}
    virtual ~ActionSave() = default;

private:
    // Keep an explicit pointer to the manager so this class does not rely
    // on any particular protected member name in the base `Action`.
    ApplicationManager* m_pManager;
};
