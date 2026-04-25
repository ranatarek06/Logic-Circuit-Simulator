#include "ActionMove.h"
#include "..\ApplicationManager.h"

ActionMove::ActionMove(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionMove::ReadActionParameters()
{
}

void ActionMove::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Move: Click a selected component to start move.");
    int sx, sy;
    pIn->GetPointClicked(sx, sy);

    Component* anchor = pManager->GetComponentAt(sx, sy);
    if (!anchor || !anchor->IsSelected())
    {
        pOut->PrintMsg("You must click a selected component to start moving. Operation cancelled.");
        return;
    }

    pOut->PrintMsg("Move: Click destination point.");
    int dx, dy;
    pIn->GetPointClicked(dx, dy);

    int deltaX = dx - sx;
    int deltaY = dy - sy;

    int n = pManager->GetCompCount();
    Component** list = pManager->GetCompList();
    for (int i = 0; i < n; ++i)
    {
        Component* c = list[i];
        if (c && c->IsSelected())
        {
            int cx, cy;
            c->GetLocation(cx, cy);
            c->SetLocation(cx + deltaX, cy + deltaY);
        }
    }

    pManager->UpdateInterface();
    pOut->ClearStatusBar();
}

void ActionMove::Undo() {}
void ActionMove::Redo() {}