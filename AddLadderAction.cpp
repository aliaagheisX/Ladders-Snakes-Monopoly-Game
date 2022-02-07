#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"


AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Grid And Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();




	///TODO: Make the needed validations on the read parameters
	
	// Read the startPos parameter
	pOut->PrintMessage("Please Click on valid Start cell.....");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("Please Click on valid End cell......");
	endPos = pIn->GetCellClicked();

	
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	//chekers
	//1-check the hcell to make sure equal each other
	//2-check start smaller than end
	//3-check end not in last row
	if ( startPos.HCell() != endPos.HCell() ||startPos.VCell() <= endPos.VCell()  || endPos.VCell() == 0) {
		pManager->GetGrid()->PrintErrorMessage("Unvalid Ladder, Click To Continue ...");
		return;
	}
	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->IsOverlapping(pLadder)) {
		pGrid->PrintErrorMessage("Unvalid Ladder, Click To Continue ...");
		delete pLadder;
		return; 
	}
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		delete pLadder;
		pGrid->PrintErrorMessage("InValid ...");

	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
