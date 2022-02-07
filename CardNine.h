#ifndef CARD_NINE
#define CARD_NINE
#include "StationCard.h"
#include "Player.h"
// [ CardNine ] Summary:

class CardNine : public StationCard
{
	static Player* pOwner; //pointer To the Owner Of Cell
	static int CardPrice; //Price Of Card
	static int Fees; // Fees To Pay When Other Players[not Owner] Stop On it
	static bool PrintOnce;
	static bool ReadOnce;


public:
	CardNine(const CellPosition& pos); // A Constructor takes card position
	CardNine(); // A Constructor takes card position
	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;
	static void Print(ofstream& OutFile, GameObjectsType Obj) ;

	static void EndPrint();
	static void EndRead();

};
#endif
