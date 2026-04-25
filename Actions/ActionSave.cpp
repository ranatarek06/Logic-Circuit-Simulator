#include "ActionSave.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <string>
using namespace std;

ActionSave::ActionSave(ApplicationManager* pApp)
    : Action(pApp)
    , m_pManager(pApp)
{
}

void ActionSave::Execute()
{
    std::ofstream OutFile("circuit.txt");
    if (!OutFile.is_open())
        return;

    m_pManager->SaveAll(OutFile);
    OutFile.close();
}