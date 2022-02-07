#include "CardFour.h"
#include "Input.h"
#include "Output.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4;
}

CardFour::CardFour() // set the cell position of the card
{
	cardNumber = 4;
}


CardFour::~CardFour()
{
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	//1-print Detaild Message about what will the card do
	Card::Apply(pGrid, pPlayer); // call card apply to print message

	//2-print to a descriptive message
	pGrid->PrintErrorMessage("This Card Will Prevent You from Rolling the next turn., Click to Continue ...");


	//3-Set Stop playing for one turn;
	pPlayer->SetTurnsToPlay(1);
}

void CardFour::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_4) {
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}

