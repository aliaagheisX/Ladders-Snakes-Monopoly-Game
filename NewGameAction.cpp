#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include "Input.h"
#include "Output.h"


NewGameAction::NewGameAction(ApplicationManager* pApp) :Action(pApp) {} // Constructor

// ============ Action Functions ============

void NewGameAction::ReadActionParameters() {
	//doesn't read any parameters
}

void NewGameAction::Execute() {
	//1-get pointer to grid
	Grid* pGrid = pManager->GetGrid();

	//2-print proper message
	pGrid->PrintErrorMessage("You Request New Game Now, Click To Continue ...");

	pGrid->resetGame();

	
}
NewGameAction::~NewGameAction() {} // Virtual Destructor