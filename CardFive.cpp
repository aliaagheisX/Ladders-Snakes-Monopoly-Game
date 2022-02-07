#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos):Card(pos)
{
	cardNumber = 5;
}


CardFive::CardFive()
{
	cardNumber = 5;
}





void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);//Apply Card

	pGrid->PrintErrorMessage("This Card Will Move you backward , Click to Continue ..."); // Print Proper Message

	CellPosition pos(GetPosition().GetCellNum() - pPlayer->getJustRolledDice());
	// Make New Position  Equal to Position OF Card - Just Rolled Dice of Player Again


	pGrid->UpdatePlayerCell(pPlayer,pos); //change The Position 


	//1-Check if the new position of Player Have Object or not
	//2-if yes then apply it
	if(pPlayer->GetCell()->GetGameObject() != NULL) 
	   pPlayer->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);
	
}

void CardFive::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_5) {
		Card::Save(OutFile, Obj);
		OutFile << '\n';
	}
}



CardFive::~CardFive()
{
}
