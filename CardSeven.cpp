#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos):Card(pos)
{
	cardNumber = 7;
}


CardSeven::CardSeven()
{
	cardNumber = 7;
}


void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);//Apply Card

	pGrid->PrintErrorMessage("This Card Will Restart game for the next player to the current , Click to Continue ..."); // Print Proper Message

	CellPosition pos(1);
	Player* x;
	
	x= pGrid->getNextPlayer(pPlayer);
	if (x == NULL)
		return;
	pGrid->UpdatePlayerCell(x, pos);//move the player to first cell(pos)

}
void CardSeven::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_7) {
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}


CardSeven::~CardSeven()
{
}