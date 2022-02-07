#include "CardEleven.h"
#include "Input.h"
#include "Output.h"

Player* CardEleven::pOwner = NULL; // inital the pointer to owner with null
int CardEleven::CardPrice = -1; //inital the price of card with -1
int CardEleven::Fees = -1; //inital the Fees of card with -1
bool CardEleven::PrintOnce = false; //inital the Fees of card with -1
bool CardEleven::ReadOnce = false; //inital the Fees of card with -1


CardEleven::CardEleven(const CellPosition& pos) : StationCard(pos, pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (9 here)
}

CardEleven::CardEleven() : StationCard(pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 11;
}




void CardEleven::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_11)
		StationCard::Save(OutFile, Obj);
}

void CardEleven::EndPrint() { PrintOnce = false; }
void CardEleven::EndRead() { ReadOnce = false; }
