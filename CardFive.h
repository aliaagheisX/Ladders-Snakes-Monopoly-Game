#pragma once
#include "Card.h"


/*
-------------------Card Summary------------------------------
Move Backward with the dice rolled

*/
const int COUNT_OF_PARA_CARD_FIVE = 0;

class CardFive : public Card
{
	

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position
	CardFive(); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
													  
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;


	virtual ~CardFive(); // A Virtual Destructor
};
