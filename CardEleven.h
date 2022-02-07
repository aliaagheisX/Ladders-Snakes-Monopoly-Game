#ifndef CARD_ELEVEN
#define CARD_ELEVEN
#include "StationCard.h"
#include "Player.h"
// [ CardNine ] Summary:

class CardEleven : public StationCard
{
	static Player* pOwner; //pointer To the Owner Of Cell
	static int CardPrice; //Price Of Card
	static int Fees; // Fees To Pay When Other Players[not Owner] Stop On it
	static bool PrintOnce;
	static bool ReadOnce;
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position
	CardEleven(); // A Constructor takes card position

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;

	static void EndPrint();
	static void EndRead();

};
#endif
