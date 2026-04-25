#pragma once
#ifndef PASTE_H
#define PASTE_H

#include "Action.h"

class Component;

class Paste : public Action
{
public:
    Paste(ApplicationManager* pApp);
    virtual void ReadActionParameters() override;
    virtual void Execute() override;
    virtual void Undo() override;
    virtual void Redo() override;

private:
    int m_x;
    int m_y;
    Component* m_pComp;
    bool m_valid;
};

#endif