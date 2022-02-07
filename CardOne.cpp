#include "CardOne.h"
#include "Input.h"
#include "Output.h"
CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::CardOne(){
	cardNumber = 1;
}

CardOne::~CardOne()
{
}

int CardOne::getWalletAmount() const { return walletAmount; }

bool CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	

	pOut->PrintMessage("New CardOne: Enter A Valid wallet amount To Decrease ...");
	walletAmount = pIn->GetInteger(pOut);

	if (walletAmount <= 0) {
		pGrid->PrintErrorMessage("The Wallet Amount Must Be Greater Than Zero, Click To Continue");
		return false; 
	}
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
	return true;
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	int x, y;
	Card::Apply(pGrid, pPlayer); // call card apply to print message
	
								 //Print Poper Message
	pGrid->GetOutput()->PrintMessage("This Card Will Decreas Your Wallet by " + to_string(walletAmount) + ", Click to Continue ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
}

void CardOne::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_1){
		Card::Save(OutFile, Obj);
		OutFile << walletAmount << '\n';
	}
}

void CardOne::Read(ifstream& InFile) {
	int walletAmount;
	Card::Read(InFile);
	InFile >> walletAmount;
	this->walletAmount = walletAmount;
	
}

void CardOne::setCopy(Card* ClipboardCard) {
	Card::setCopy(ClipboardCard);
	this->walletAmount = static_cast<CardOne*>(ClipboardCard)->getWalletAmount();
}
