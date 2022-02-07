#ifndef CARD_TWO
#define CARD_TWO


#include "Card.h"

/*
-------------------Card Summary------------------------------
it transfer current player to start of Next Ladder
if there's no next ladder it will do nothing

*/
class CardTwo : public Card
{	
public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position
	CardTwo(); // A Constructor takes card position

	 // Doesn't Need Parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by Transfer Player To Next Ladder
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;



	virtual ~CardTwo(); // A Virtual Destructor
};

#endif