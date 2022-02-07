#ifndef CARD_TWELVE
#define CARD_TWELVE
#include "Card.h"
class CardTwelve :public Card
{
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position
	CardTwelve(); // A Constructor takes card position

	// Doesn't Read Parameters
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;


	virtual ~CardTwelve(); // A Virtual Destructor
};

#endif