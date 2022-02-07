#include "CardTwelve.h"
#include "StationCard.h"
#include "Input.h"
#include "Output.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwelve::CardTwelve() // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwelve::~CardTwelve()
{
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("this Card Will Transfet The Most Expensive Station You Have To The Poorest Player, Click To Continue ...");

	StationCard* station = pGrid->GetCurrentPlayer()->getExpensiveStation();

	if(station)
		station->setOwnership(pGrid->getPoorestPlayer());

	
}

void CardTwelve::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_12) {
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}
