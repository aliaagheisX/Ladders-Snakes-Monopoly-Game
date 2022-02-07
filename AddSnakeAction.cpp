#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	//chekers
	//1-check the hcell to make sure equal each other
	//2-check start greater than end
	//3-check end not in first row
	if (startPos.VCell() >= endPos.VCell() || startPos.HCell() != endPos.HCell() || endPos.VCell() == NumVerticalCells - 1){
		pManager->GetGrid()->PrintErrorMessage("Unvalid Snake, Click To Continue ...");
		return;
	}
	// Create a Ladder object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->IsOverlapping(pSnake)) {
		pGrid->PrintErrorMessage("Error: Cell already has a Snake ! Click to continue ...");
		delete pSnake;
		return; 
	}
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		delete pSnake;
		pGrid->PrintErrorMessage("InValid ...");

	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
}