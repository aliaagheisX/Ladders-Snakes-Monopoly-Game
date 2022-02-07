#ifndef CARD_ONE
#define CARD_ONE
#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardOne :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardOne(const CellPosition& pos); // A Constructor takes card position
	CardOne(); // A Constructor takes card position

	int getWalletAmount() const;

	virtual bool ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;



	virtual void Read(ifstream& InFile);

	virtual void setCopy(Card* ClipboardCard);

	virtual ~CardOne(); // A Virtual Destructor
};
#endif
