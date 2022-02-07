#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"
#include "Input.h"
#include "Output.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp):Action(pApp){} // Constructor

// ============ Action Functions ============

void InputDiceValueAction::ReadActionParameters(){
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	

	pOut->PrintMessage("Please Enter a Valid Dice Value...");

	diceNumber = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();
}

void InputDiceValueAction::Execute(){
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	// 1-1 Check if the Game is ended
	if (pGrid->GetEndGame()) {
		pGrid->PrintErrorMessage("The Game Ended, Click To Continue...");
		return;
	}

	//1-2 check if the player Enter Wrong Dice Number
	if (diceNumber > 6 || diceNumber < 1) {
		pGrid->PrintErrorMessage("Unvalid Dice Value, Click To Continue");
		return;
	}

	// 2- Get the "current" player from pGrid
	Player* pPlayer = pGrid->GetCurrentPlayer();

	// 3- Move the currentPlayer using function Move of class player
	pPlayer->Move(pGrid, diceNumber);

	// 4- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

}
InputDiceValueAction::~InputDiceValueAction(){} // Virtual Destructor