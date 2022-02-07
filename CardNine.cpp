#include "CardNine.h"
#include "Input.h"
#include "Output.h"

Player* CardNine::pOwner = NULL; // inital the pointer to owner with null
int CardNine::CardPrice = -1; //inital the price of card with -1
int CardNine::Fees = -1; //inital the Fees of card with -1
bool CardNine::PrintOnce = false; //inital the Fees of card with -1
bool CardNine::ReadOnce = false; //inital the Fees of card with -1


CardNine::CardNine(const CellPosition& pos) : StationCard(pos, pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 9;
}

CardNine::CardNine() : StationCard(pOwner, CardPrice, Fees, PrintOnce, ReadOnce) // set the cell position of the card
{
	cardNumber = 9;
}




void CardNine::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_9)
		StationCard::Save(OutFile, Obj);
}
void CardNine::Print(ofstream& OutFile, GameObjectsType Obj) {

}

void CardNine::EndPrint() { PrintOnce = false; }
void CardNine::EndRead() { ReadOnce = false; }
