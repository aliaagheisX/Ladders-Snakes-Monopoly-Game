#ifndef CARD_Four
#define CARD_Four

#include "Card.h"


/*
-------------------Card Summary------------------------------
Prevent You from Rolling the next turn

*/
class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position
	CardFour (); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // Give Them Extra Roll Dice
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;


	virtual ~CardFour(); // A Virtual Destructor
};

#endif