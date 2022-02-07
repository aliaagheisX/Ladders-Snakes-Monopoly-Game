#ifndef CARD
#define CARD

#include <fstream>
#include "GameObject.h"
#include "GameObjectTypes.h"
#include "CellPosition.h"
#include "Player.h"

// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
protected:
	int cardNumber; // an integer representing the card number

public:
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it

	Card(); //default constructor used in OpenGrid 
			//set some default values to card as position = CellPosition(1) -> first Cell in Grid

	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number

	void setCardPosition(const CellPosition &position); // the setter of Position USED in paste Card
														// as it use Default Copy Constructor to all data in pointer of card in Clipboard
														// so need to change the position after that

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual bool ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)


	virtual Card* getCopy(Card* ClipboardCard) const;
	virtual void setCopy(Card * ClipboardCard);

	virtual void Save(ofstream& OutFile, GameObjectsType Obj) const ;

	virtual void Read(ifstream& InFile);

	virtual GameObject* Load(ifstream& InFile);
	virtual ~Card(); // A Virtual Destructor
};
#endif
