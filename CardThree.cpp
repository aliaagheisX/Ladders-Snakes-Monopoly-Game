#include "CardThree.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "ApplicationManager.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3;
}

CardThree::CardThree()// set the cell position of the card
{
	cardNumber = 3;
}



CardThree::~CardThree()
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	
	Card::Apply(pGrid, pPlayer); // call card apply to print message
	
	//1-print Detaild Message about what will the card do
	pGrid->PrintErrorMessage("This Card Will Give You Extra RollDice, Click to Continue ...");
	

	//2-loop through players tell next him
	for (int i = 0; i < MaxPlayerCount - 1; i++) pGrid->AdvanceCurrentPlayer();
	// After That The Player Can Roll Again
	
}

void CardThree::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_3) {
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}

