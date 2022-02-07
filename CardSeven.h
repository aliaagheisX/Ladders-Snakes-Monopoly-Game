#pragma once
#include "Card.h"


/*
-------------------Card Summary------------------------------
The player next to current player will be restarted

*/
const int COUNT_OF_PARA_CARD_SEVEN = 0;

class CardSeven : public Card
{


public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position
	CardSeven(); // A Constructor takes card position
	
				 
				 // Doesn't Need Parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the next Player

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;



	virtual ~CardSeven(); // A Virtual Destructor
};
