#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\Components\SWITCH.h"
#include "..\Components\AND2.h"
#include "..\Components\LED.h"
#include "..\Components\OR2.h"
#include "..\Components\BUF.h"
#include "..\Components\INV.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
#include <string>
using namespace std;

ActionLoad::ActionLoad(ApplicationManager* pApp)
    : Action(pApp)
{
}

void ActionLoad::Execute()
{
    ifstream InFile("circuit.txt");
    if (!InFile)
        return;

    pManager->ClearAll();

    string Type;
    while (InFile >> Type)
    {
        if (Type == "END")
            break;

        Component* pComp = NULL;
        GraphicsInfo Gfx = { 0,0,0,0 };

        if (Type == "SWITCH")
            pComp = new SWITCH(Gfx, SWITCH_FANOUT);
        else if (Type == "AND2")
            pComp = new AND2(Gfx, AND2_FANOUT);
        else if (Type == "LED")
            pComp = new LED(Gfx, LED_FANOUT);

        if (pComp)
        {
            pComp->Load(InFile);
            pManager->AddComponent(pComp);
        }
    }

    InFile.close();
}
