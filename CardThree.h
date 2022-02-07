#ifndef CARD_THREE
#define CARD_THREE

#include "Card.h"


/*
-------------------Card Summary------------------------------
roll extra dice

*/
class CardThree : public Card
{
public:
	CardThree(const CellPosition& pos); // A Constructor takes card position
	CardThree(); // A Constructor takes card position

	// Doesn't Need Parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // Give Them Extra Roll Dice
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;


	virtual ~CardThree(); // A Virtual Destructor
};

#endif