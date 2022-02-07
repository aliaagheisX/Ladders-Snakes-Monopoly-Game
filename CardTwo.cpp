#include "CardTwo.h"
#include "Ladder.h"
#include "Input.h"
#include "Output.h"
CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2;
}


CardTwo::CardTwo()// set the cell position of the card
{
	cardNumber = 2;
}


CardTwo::~CardTwo()
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	//1-print Detaild Message about what will the card do

	Card::Apply(pGrid, pPlayer); // call card apply to print message

	//Proper Message
	pGrid->PrintErrorMessage("This Card Will Move You To Start OF Next Ladder, Click to Continue ...");

	//2-Get Position OF Next Ladder From Grid
	Ladder *NextLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());

	//3-if Null Do Nothing
	if (NextLadder == NULL) return;

	//4-if Not Null transfer Player To it
	pGrid->UpdatePlayerCell(pPlayer, NextLadder->GetPosition());


	//4-if there's object in stopped cell aplly it
	if (pPlayer->GetCell()->GetGameObject() != NULL)
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
}

void CardTwo::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_2){
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}