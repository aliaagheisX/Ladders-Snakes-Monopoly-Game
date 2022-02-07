#ifndef STATION
#define STATION
#include "Card.h"
#include "Player.h"
// [ station card ] Summary:

class StationCard : public Card
{
private:
	 Player* &pOwner; //pointer To the Owner Of Cell
	 int &CardPrice; //Price Of Card
	 int &Fees; // Fees To Pay When Other Players[not Owner] Stop On it
	 bool& PrintOnce;
	 bool &ReadOnce;

public:
	StationCard(const CellPosition& pos, Player*&, int&, int&, bool&, bool&); // A Constructor takes card position
	StationCard(Player*&, int&, int&, bool&, bool&); // A Constructor takes card position

	virtual bool ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const;

	virtual void Read(ifstream& InFile);


	virtual int getCardPrice() const;
	virtual int getFees() const;

	static void setEndToSave();

	virtual void setOwnership(Player *pPlayer);


	virtual void setCopy(Card* ClipboardCard);

	static void EndPrint();
	static void EndRead();


	virtual ~StationCard(); // A Virtual Destructor
};
#endif
