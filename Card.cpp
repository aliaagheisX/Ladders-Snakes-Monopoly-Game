#include "Card.h"
#include"Input.h"
#include"CellPosition.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

Card::Card() {
	//Default Constructor Use In OpenGridAction
}

void Card::SetCardNumber(int cnum)
{  
	// check the validation 
	if (cardNumber > 0 && cardNumber <= 12)
		cardNumber = cnum;
}

int Card::GetCardNumber() { return cardNumber; }

void Card::Draw(Output* pOut) const
{
	///DONE: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);
}

bool Card::ReadCardParameters(Grid * pGrid)
{

	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
	return true;
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	//print proper Message 
	//this will be overridden by all cards
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ", Click to continue ...");
}

void Card::setCardPosition(const CellPosition& position) {
	this->position = position; //change the position of the card by the passed cellPosition
}

//this function will be overriding in all Cards just to check type and print Parameters if exsist
void Card::Save(ofstream& OutFile, GameObjectsType Obj) const {
	//in GameObjectsType 
	//OBJ_CARD_1 = 1
	//and so on till OBJ_CARD_12
	//so the number of card that will be printed == the Obj

	//1-print the number of card save
	OutFile << Obj << ' ';

	//2-print the number of cell of position 
	GameObject::Save(OutFile, Obj);
}


//we don't to reed the cellNum
// the Load Read it
//as it specify the type of card by it
void Card::Read(ifstream& InFile) {
	//read the position
	GameObject::Load(InFile);
}

GameObject* Card::Load(ifstream& InFile) {
	int cardNumber;
	InFile >> cardNumber;
	Card* pCard = NULL;
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne();
		break;
	case 2:
		pCard = new CardTwo();
		break;
	case 3:
		pCard = new CardThree();
		break;
	case 4:
		pCard = new CardFour();
		break;
	case 5:
		pCard = new CardFive();
		break;
	case 6:
		pCard = new CardSix();
		break;
	case 7:
		pCard = new CardSeven();
		break;
	case 8:
		pCard = new CardEight();
		break;
	case 9:
		pCard = new CardNine();
		break;
	case 10:
		pCard = new CardTen();
		break;
	case 11:
		pCard = new CardEleven();
		break;
	case 12:
		pCard = new CardTwelve();
		break;
	}
	pCard->Read(InFile);
	return pCard;
}
void Card::setCopy(Card* ClipboardCard) {
	this->position = ClipboardCard->position;
	this->cardNumber = ClipboardCard->GetCardNumber();
}

Card* Card::getCopy(Card* ClipboardCard) const {
	int CardNumber = ClipboardCard->GetCardNumber();
	Card* pCard = NULL;
	switch (CardNumber)
	{
	case 1:
		pCard = new CardOne();
		break;
	case 2:
		pCard = new CardTwo();
		break;
	case 3:
		pCard = new CardThree();
		break;
	case 4:
		pCard = new CardFour();
		break;
	case 5:
		pCard = new CardFive();
		break;
	case 6:
		pCard = new CardSix();
		break;
	case 7:
		pCard = new CardSeven();
		break;
	case 8:
		pCard = new CardEight();
		break;
	case 9:
		pCard = new CardNine();
		break;
	case 10:
		pCard = new CardTen();
		break;
	case 11:
		pCard = new CardEleven();
		break;
	case 12:
		pCard = new CardTwelve();
		break;
	}
	pCard->setCopy(ClipboardCard);
	return pCard;
}


Card::~Card()
{
}
