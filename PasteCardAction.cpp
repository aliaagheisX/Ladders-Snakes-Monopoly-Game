#include "PasteCardAction.h"
#include "CellPosition.h"
#include "Grid.h"
#include "Card.h"
#include "Output.h"
#include "Input.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteCardAction::ReadActionParameters()
{
	//1-Git Pointer To Grid
	Grid* pGrid = pManager->GetGrid(); 

	//2-1Print Proper Message
	pGrid->GetOutput()->PrintMessage("You Request A Paste Card Please Click on Proper Cell, Click To Continue ...");

	//2-2 get Cell Clicked
	destinationCard = pGrid->GetInput()->GetCellClicked();
	//2-3 Clear Status bar
	pGrid->GetOutput()->ClearStatusBar();

	//3-Validation check if it has card or Not 

}

void PasteCardAction::Execute()
{
	//1-Read ActionPArameters
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->HasCard(destinationCard)) {
		//if cell clicked has card print error message
		pGrid->PrintErrorMessage("You Selected a Cell That Has Already Card, Click To Continue...");
		return;
	}

	//2-get Pointers to card in clipboard
	Card* ClipboardCard = pGrid->GetClipboard();

	if(ClipboardCard){

		Card* pCard = new Card(); // make new card by default constructor
	
		pCard = pCard->getCopy(ClipboardCard); //get copy 
											   //by calling in the card which be overriden with each card type
											   //return new card

		pCard->setCardPosition(destinationCard); //change the position as it make copy with same position of clipboard

		pGrid->AddObjectToCell(pCard); //added to grid
	}
}

PasteCardAction::~PasteCardAction()
{
}
