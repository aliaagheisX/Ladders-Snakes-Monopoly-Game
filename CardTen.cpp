#include "CardTen.h"
#include "Input.h"
#include "Output.h"

Player* CardTen::pOwner = NULL; // inital the pointer to owner with null
int CardTen::CardPrice = -1; //inital the price of card with -1
int CardTen::Fees = -1; //inital the Fees of card with -1
bool CardTen::PrintOnce = false; //inital the Fees of card with -1
bool CardTen::ReadOnce = false; //inital the Fees of card with -1


CardTen::CardTen(const CellPosition& pos) : StationCard(pos, pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 10;// set the inherited cardNumber data member with the card number (9 here)
}

CardTen::CardTen() : StationCard(pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 10;
}




void CardTen::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_10)
		StationCard::Save(OutFile, Obj);
}

void CardTen::EndPrint() { PrintOnce = false; }
void CardTen::EndRead() { ReadOnce = false; }

