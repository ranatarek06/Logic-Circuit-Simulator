#pragma once
#ifndef CUT_H
#define CUT_H

#include "Action.h"

class Cut : public Action
{
public:
    Cut(ApplicationManager* pApp);
    virtual void Execute() override;
    virtual void Undo() override {}
    virtual void Redo() override {}
    virtual void ReadActionParameters() override {}
};

#endif