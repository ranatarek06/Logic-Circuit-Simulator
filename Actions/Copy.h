#pragma once
#ifndef COPY_H
#define COPY_H

#include "Action.h"
#include "..\Components\Component.h"

class Copy : public Action
{
private:


public:
    Copy(ApplicationManager* pApp);


    virtual void Execute() override;

    virtual void ReadActionParameters() override {}
    virtual void Undo() override {}
    virtual void Redo() override {}
};

#endif