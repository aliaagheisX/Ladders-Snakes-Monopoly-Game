#ifndef CARD_Eight
#define CARD_Eight

#include "Card.h"


/*
-------------------Card Summary------------------------------
roll extra dice

*/
class CardEight : public Card
{
	int Amount;
public:
	CardEight(const CellPosition& pos); // A Constructor takes card position
	CardEight(); // A Constructor takes card position

	int getAmount() const;

	virtual bool ReadCardParameters(Grid* pGrid); // Doesn't Need Parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // Give Them Extra Roll Dice
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;

	virtual void Read(ifstream& InFile);

	virtual void setCopy(Card* ClipboardCard);

	virtual ~CardEight(); // A Virtual Destructor
};

#endif