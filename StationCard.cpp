#include "StationCard.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
StationCard::StationCard(const CellPosition& pos, Player* &pOwner, int &CardPrice, int& Fees, bool &PrintOnce, bool &ReadOnce) : Card(pos), pOwner(pOwner), CardPrice(CardPrice), Fees(Fees), PrintOnce(PrintOnce),ReadOnce(ReadOnce) // set the cell position of the card
{
}

StationCard::StationCard(Player*& pOwner, int& CardPrice, int& Fees, bool& PrintOnce, bool& ReadOnce) : pOwner(pOwner), CardPrice(CardPrice), Fees(Fees), PrintOnce(PrintOnce),ReadOnce(ReadOnce) // set the cell position of the card
{
}


StationCard::~StationCard()
{
}

bool StationCard::ReadCardParameters(Grid* pGrid)
{
	if (CardPrice == -1 && Fees == -1) // if the card Price and Fees Didn't initialize yet
	{
		pGrid->GetOutput()->PrintMessage("Please Enter The Price of Cell...");
		CardPrice = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		//Check The Validation

		if (CardPrice < 0) {//if invalid
			pGrid->PrintErrorMessage("You Entered UnVaild Value, Click To Continue"); // print error message
			return false;
		}
		pGrid->GetOutput()->PrintMessage("Please Enter The Fees of Cell...");
		Fees = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

		if (Fees < 0) {//if invalid
			pGrid->PrintErrorMessage("You Entered UnVaild Value, Click To Continue"); // print error message
			return false;
		}
		pGrid->GetOutput()->ClearStatusBar(); // Clear Status Bar
	}
	return true;
}



void StationCard::Apply(Grid* pGrid, Player* pPlayer)
{
	if (pOwner == NULL) { // if there's no owner yet


		//check if the player wanted to buy it
		pGrid->GetOutput()->PrintMessage("Do You Want To Buy This Card With Price " + to_string(CardPrice) + " And Fees " + to_string(Fees) + " Enter 1/0 where 0 = No AND 1 = Yes");
		bool Buy = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		pGrid->GetOutput()->ClearStatusBar();

		if (!Buy) return;//if Not Buying then Don't Do thing

		if (pPlayer->GetWallet() < CardPrice)  //if Have No Money To Buy it
		{
			//print error message and do nothing
			pGrid->PrintErrorMessage("You Have No Money To Buy Card, Click To Continue ...");
			return;
		}

		//if buy and have enough money
		//
		// 1- Set the OwnerShip
		setOwnership(pPlayer);
		// 3- Decrease the Wallet
		pOwner->SetWallet(pOwner->GetWallet() - CardPrice);

		return;// End the function
	}

	// if there's owner and all value set correctly
	// check that player stop not the Owner
	if (pPlayer != pOwner) {
		pGrid->PrintErrorMessage("You Stop On Card Nine You Need To Pay Fees " + to_string(Fees) + " Click To Continue");
		pOwner->SetWallet(pOwner->GetWallet() + Fees);
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
	}


}

void StationCard::Save(ofstream& OutFile, GameObjectsType Obj) const {
	Card::Save(OutFile, Obj);
	
	if (PrintOnce == false) {
		OutFile << CardPrice << ' ' << Fees;
		PrintOnce = true;
	}
	OutFile << '\n';
}


void StationCard::Read(ifstream& InFile) {
	
	Card::Read(InFile);
	int CardPrice, Fees;

	if(ReadOnce == false){

		InFile >> CardPrice >> Fees;

		this->CardPrice = CardPrice;

		this->Fees = Fees;

		ReadOnce = true;
	}

}

int StationCard::getCardPrice() const { return CardPrice; }
int StationCard::getFees() const {return Fees;}

void StationCard::setOwnership(Player* pPlayer) {

	if (pOwner != NULL) pOwner->removeStation(this);

	pOwner = pPlayer;

	if(pOwner != NULL)
		pOwner->addStation(this);
}

void StationCard::setEndToSave() {}

void StationCard::setCopy(Card* ClipboardCard) {
	Card::setCopy(ClipboardCard);

	this->CardPrice = static_cast<StationCard*>(ClipboardCard)->getCardPrice();
	this->Fees = static_cast<StationCard *>(ClipboardCard)->getFees();
}

void StationCard::EndPrint() {
	CardNine::EndPrint();
	CardTen::EndPrint();
	CardEleven::EndPrint();
}
void StationCard::EndRead() {
	CardNine::EndRead();
	CardTen::EndRead();
	CardEleven::EndRead();
}