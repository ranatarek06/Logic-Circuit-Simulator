#ifndef SIMULATION_MODE_H
#define SIMULATION_MODE_H

#include "Defs.H" 
#include <string>

class ApplicationManager;
class Component;

class SimulationMode
{
private:
    ApplicationManager* pManager; 

public:
    // Constructor
    SimulationMode(ApplicationManager* pApp);

    // 1. Circuit Validation (CVALID)
    bool validateCircuit() const;

    // 2. Simulate Circuit Operation (SIMC) - Runs one step of signal propagation
    void simulateCircuit();

    // 3. Truth Table Generation (TTB) - Tests all input combinations
    void generateTruthTable();

    // 4. Pin Probing (CPR) - Gets the status of a clicked connection/pin
    STATUS getPinStatus(int x, int y) const;
};

#endif