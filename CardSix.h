#pragma once
#include "Card.h"


/*
-------------------Card Summary------------------------------
Move to cell user entered

*/
class CardSix : public Card
{
	CellPosition nextPosition; //the position the user entered in design mood

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position
	CardSix(); // A Constructor takes card position

	CellPosition getNextPosition() const;
	virtual bool ReadCardParameters(Grid* pGrid); //take the parameter of the position that player should move to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;

	virtual void Read(ifstream& InFile);

	virtual void setCopy(Card* ClipboardCard);

	virtual ~CardSix(); // A Virtual Destructor
};