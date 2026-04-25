#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "Actions/Action.h"
#include "Components/Component.h"
//#include <vector>
#include <string>
using namespace std;

class SimulationMode;

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

	SimulationMode* pSimMode;

	Component* Clipboard = nullptr;

	// Helper functions for simulation
	//void PropagateSignal(Component* startComp);

public:
	ApplicationManager(); //constructor
	void DeleteComponent(Component* pComp);

	Component* GetComponentByLocation(int x, int y);
	void SetClipboard(Component* Comp);
	Component* GetClipboard();
	void RemoveComponent(Component* Comp);

	Component* GetSelectedComponent() const;

	void SaveAll(ofstream& OutFile);
	void ClearAll();

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	SimulationMode* GetSimulationMode() const;

	// ============ NEW: SIMULATION FUNCTIONS ============

	GraphicsInfo GetComponentGraphics(int index) const;
	// 1. Circuit Validation
	//bool ValidateCircuit();

	// 2. Real-time Switch Toggle Simulation
	//bool ToggleSwitch(int x, int y);

	// 3. Truth Table Generation
	//void GenerateTruthTable();

	// 4. Circuit Probing
	//string ProbeCircuit(int x, int y);

	// Helper functions for simulation
	/*vector<Component*> GetAllSwitches() const;
	vector<Component*> GetAllLEDs() const;
	vector<Component*> GetAllGates() const;
	void ResetAllComponents();
	void SimulateForTruthTable(const vector<Component*>& switches,
		const vector<Component*>& leds,
		vector<bool>& outputValues);*/

	// Existing accessors
	Component* GetCompAt(int index) const;
	
	int GetCompCount() const { return CompCount; }
	Component** GetCompList() { return CompList; }
	Component* GetComponentAt(int x, int y) const;

	//destructor
	~ApplicationManager();
};

#endif