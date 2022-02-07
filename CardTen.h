#ifndef CARD_TEN
#define CARD_TEN
#include "StationCard.h"
#include "Player.h"
// [ CardNine ] Summary:

class CardTen : public StationCard
{
	static Player* pOwner; //pointer To the Owner Of Cell
	static int CardPrice; //Price Of Card
	static int Fees; // Fees To Pay When Other Players[not Owner] Stop On it
	static bool PrintOnce;
	static bool ReadOnce;
public:
	CardTen(const CellPosition& pos); // A Constructor takes card position
	CardTen(); // A Constructor takes card position

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;

	static void  EndPrint();
	static void  EndRead();


};
#endif
