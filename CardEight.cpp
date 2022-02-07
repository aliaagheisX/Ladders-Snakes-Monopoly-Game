#include "CardEight.h"
#include "Input.h"
#include "Output.h"
CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8;
	Amount = 0;
}

CardEight::CardEight()// set the cell position of the card
{
	cardNumber = 8;
	Amount = 0;
}

CardEight::~CardEight()
{
}

int CardEight::getAmount() const { return Amount; }


bool CardEight::ReadCardParameters(Grid* pGrid)
{
	//print proper message
	pGrid->GetOutput()->PrintMessage("Enter Amount You Must Pay , Click to Continue ...");

	//wait for integer input
	Amount = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	//check the validation and print proper message
	if (Amount <= 0) {
		pGrid->PrintErrorMessage("Unvalid Value, Click To Continue ...");
		return false;
	}

	pGrid->GetOutput()->ClearStatusBar(); //clear statur bar
	return true;//return true if everthing okay
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	bool willPay=0;

	Card::Apply(pGrid, pPlayer); // call card apply to print message

	//2-print to a descriptive message
	pGrid->PrintErrorMessage("If you Will Pay Enter any number else Enter 0");
	//3-get if the player will to play
	willPay=pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	if (willPay) // if true
	{
		pGrid->PrintErrorMessage("You Will Pay Click to Continue ... ");
		if (pPlayer->GetWallet() >= Amount) // check if the player have money to pay
			pPlayer->SetWallet(pPlayer->GetWallet() - Amount);// if true then make him pay
		else
			willPay = false;//if not change the willPlay To False
	}

	//4-if he not will Play By His Option OR by his Wallet
	if (!willPay) {
		pGrid->PrintErrorMessage("You Will Stay in Prison Click to Continue ... ");//print Proper Message
		pPlayer->SetTurnsToPlay(3);	//Set Stop playing for three turn
	}
}

void CardEight::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_8) {

		Card::Save(OutFile, Obj);

		OutFile << Amount << '\n';
	}
}

void CardEight::Read(ifstream& InFile) {
		Card::Read(InFile);
		int Coins;
		InFile >> Coins;
		this->Amount = Coins;
}

void CardEight::setCopy(Card* ClipboardCard) {
	Card::setCopy(ClipboardCard);
	Amount = static_cast<CardEight*>(ClipboardCard)->getAmount();
}
