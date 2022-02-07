#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

CardSix::CardSix()
{
	cardNumber = 6;
}

CellPosition CardSix::getNextPosition() const { return nextPosition;}


bool CardSix::ReadCardParameters(Grid* pGrid)
{
	// no need for parameters
	pGrid->GetOutput()->PrintMessage("Click on Cell You Want The Player Move To, Click to Continue ...");

	nextPosition = pGrid->GetInput()->GetCellClicked();

	//check for validation
	//1- check it's not card
	if (nextPosition.GetCellNum() == position.GetCellNum() || !nextPosition.IsValidCell()) {
		pGrid->PrintErrorMessage("Unvalid Cell, Click To Continue ...");
		return false;
	}

	pGrid->GetOutput()->ClearStatusBar();
	return true;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("This Will Move you to Other Cell, Click to Continue ..."); //print proper message

	pGrid->UpdatePlayerCell(pPlayer, nextPosition);//change the position of player to the entered Next position

	//1-Check if the new position of Player Have Object or not
	//2-if yes then apply it
	GameObject* pObj = pPlayer->GetCell()->GetGameObject();

	if (pPlayer->GetCell()->GetGameObject() != NULL){
		GameObject* pObj = pPlayer->GetCell()->GetGameObject();
		if (dynamic_cast<CardSix*>(pObj) && static_cast<CardSix*>(pObj)->getNextPosition().GetCellNum() == position.GetCellNum())
		{
			pGrid->PrintErrorMessage("This Will Cause Infinity Loop, Click To Continue ...");
			return;
		}
		pObj->Apply(pGrid, pPlayer);
	}
}

void CardSix::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_CARD_6) {
		Card::Save(OutFile, Obj);
		OutFile << nextPosition.GetCellNum() << '\n';
	}
}

void CardSix::Read(ifstream& InFile) {
		Card::Read(InFile);
		int cellNum;
		InFile >> cellNum;
		nextPosition = CellPosition::GetCellPositionFromNum(cellNum);
	
}


void CardSix::setCopy(Card* ClipboardCard){
	Card::setCopy(ClipboardCard);
	nextPosition = static_cast<CardSix*>(ClipboardCard)->getNextPosition();
}


CardSix::~CardSix()
{
}