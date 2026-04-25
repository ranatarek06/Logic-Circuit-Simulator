#include "AddConnection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp)
{
    x1 = y1 = x2 = y2 = 0;
}

void AddConnection::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    pOut->PrintMsg("Click source component");
    pIn->GetPointClicked(x1, y1);

    pOut->PrintMsg("Click destination component");
    pIn->GetPointClicked(x2, y2);

    pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
    // Read parameters (two clicks) first
    ReadActionParameters();

    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    Component* SrcComp = pManager->GetComponentAt(x1, y1);
    if (!SrcComp) { pOut->PrintMsg("No source component"); return; }
    pOut->PrintMsg(SrcComp->GetOutputPin() ? "Source has output pin" : "Source missing output pin");

    OutputPin* SrcPin = SrcComp->GetOutputPin();
    if (!SrcPin) { pOut->PrintMsg("Source component has no output pin"); return; }

    Component* DstComp = pManager->GetComponentAt(x2, y2);
    if (!DstComp) { pOut->PrintMsg("No destination component"); return; }
    pOut->PrintMsg(DstComp->GetInputPin(0) ? "Destination has input pin" : "Destination missing input pin");

    InputPin* DstPin = DstComp->GetInputPin(0); 
    if (!DstPin) { pOut->PrintMsg("Destination component has no input pin (or busy)"); return; }

    GraphicsInfo GInfo;
    GInfo.x1 = SrcComp->GetGraphicsInfo().x2;
    GInfo.y1 = (SrcComp->GetGraphicsInfo().y1 + SrcComp->GetGraphicsInfo().y2) / 2;
    GInfo.x2 = DstComp->GetGraphicsInfo().x1;
    GInfo.y2 = (DstComp->GetGraphicsInfo().y1 + DstComp->GetGraphicsInfo().y2) / 2;

    Connection* pConn = new Connection(GInfo, SrcPin, DstPin);
    pManager->AddComponent(pConn);
    DstPin->setConnected(true);

    pOut->ClearStatusBar();
}

void AddConnection::Undo()
{
    // implement undo logic later (remove the last-added connection or track created connection)
}

void AddConnection::Redo()
{
    // implement redo logic later
}
