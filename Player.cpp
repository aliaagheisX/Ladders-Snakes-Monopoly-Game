#include "Player.h"

#include "GameObject.h"
#include "StationCard.h"
#include "FireAttack.h"
#include "PoisonAttack.h"
#include "IceAttack.h"
#include "LightningAttack.h"



//set all initial values
Player::Player(Cell * pCell, int playerNum) : playerNum(setPlayerNum(playerNum)) //to validate the playerNumber before set it
{

	
	SetCell(pCell);			  // validate and set Cell of Player

	SetWallet(INITAL_WALLET); // set wallet to constant INITAL_WALLET = 100

	this->turnCount = 0; 	  // set turn count to 0

	stationsCount = 0;		  // set stations count to 0
							  // we can loop and set all stations to NULL but it unnecessary
							  // as StationsCount will stop us from accessing garbage data

	stepCount = 0;			  // set step count to 0 
	turnsToPlay = 0;		  // set turns to play to 0

	Burned = 0;
	Poisoned = 0;

	attackCount = 0;

}

void Player::resetPlayer(Grid * pGrid, Cell * pCell) {

	SetWallet(INITAL_WALLET); //reset the wallet of player to inital value
	
	pGrid->UpdatePlayerCell(this, pCell->GetCellPosition()); //reset the player position to given posisiton
															 //in grid it pass CellList[NumVerticalCells - 1][0] -> the CellPosition Number = 1
	
	turnCount = 0;		// reset turn count to 0
	stepCount = 0;		// reset step count to 0 
	turnsToPlay = 0	;	// reset turns to play to 0


	//REMOVE STATIONS
	for (int i = 0; i < stationsCount; i++) {

		stations[i]->setOwnership(NULL); //1- change the OwnerShip To NULL

		stations[i] = NULL;				//2- remove the pointer to the station
										//	 by setting it to NULL
	}
	stationsCount = 0;				    //3- set stations count to 0

		//REMOVE Attacks
	for (int i = 0; i < attackCount; i++) {

		delete attacks[i];				//1- delete attack

		attacks[i] = NULL;				//2-set attack to NULL
	}
	attackCount = 0;				    //3- set attacks count to 0
}

void Player::addStation(StationCard* station) {
	stations[stationsCount++] = station; // add pointer to stations and increase count of stations
}

StationCard* Player::getExpensiveStation() {
	if (stationsCount == 0) return NULL; //if there is no station [count of stations = 0] return NULL

	StationCard* Expensive = stations[0]; //1-initalize the Expensive station to first station

	//2-Loop through all stations the player have
	for (int i = 0; i < stationsCount; i++) { 

		//3-Compare between them by CardPrice of Each One
		if (stations[i]->getCardPrice() > Expensive->getCardPrice()) 
			Expensive = stations[i];  //4-set the expensive to the gretter value in [cardPrice]

	}
	return Expensive;//5-return pointer to the expensive station
}

void Player::removeStation(StationCard* station) {
	//1-loop through the stations the player have
	for (int i = 0; i < 3; i++) {
		//2-check if it's the station to remove or not
		if (stations[i] == station) {
			//3- if found deleted it
			station = NULL;
			//4-then shifted all stations to back and decrease the stations count
			for (int j = i; j < --stationsCount; j++)
				stations[j] = stations[j + 1];

			return;//end the function if founded and removed
		}
	}
}

// ====== Setters  ======

void Player::SetCell(Cell * cell) 
{
	if (cell->GetCellPosition().IsValidCell()) {//make sure it valid cell
		pCell = cell;
		stepCount = pCell->GetCellPosition().GetCellNum();//make sure stepCount = Cell Number He Stop On It
	}
}

void Player::SetWallet(int wallet)
{
	wallet = wallet < 0 ? 0 : wallet; // validate to make sure not to become less than zero
	this->wallet = wallet;
}

int Player::setPlayerNum(int number) {
	number = number < 0 || number >= MaxPlayerCount ? 0 : number; // validate to make sure not to become less than zero or greater than maximum player count
	return number;
}

void Player::SetTurnsToPlay(int Stopturns) {
	Stopturns = Stopturns > 0 ? Stopturns : 0; // validate to make sure not to become less than zero
	turnsToPlay = Stopturns;
}

void Player::setBurn(int turns){
	if(turns >= 0 || turns <= MAX_TURNS_TO_BURN)
		Burned = turns;
}

void Player::setPoison(int turns) {
	if (turns >= 0 || turns <= MAX_TURNS_TO_POISON)
		Poisoned = turns;
}
bool Player::addAttack(Attack* attack) {
	if (attackCount == MAX_ATTACKS) return false;
	for (int i = 0; i < attackCount; i++) {
		if (attacks[i]->CompareAttackType(attack))
			return false;
	}
	attacks[attackCount++] = attack;
	return true;
}

// ====== Getters  ======

Cell* Player::GetCell() const { return pCell; }

int Player::GetWallet() const { return wallet; }

int Player::getPlayerNum() const { return playerNum; }

int Player::getTurnsToPlay() const { return turnsToPlay; }

int Player::getJustRolledDice() const { return justRolledDiceNum; }

int Player::getStepCount() const { return stepCount; }

int Player::GetTurnCount() const { return turnCount; }


// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[getPlayerNum()]; //Get The Player Colour By it's Number

	pOut->DrawPlayer(GetCell()->GetCellPosition(), getPlayerNum(), playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard; //Get The Cell Colour By Know if it's Card Or Not
	
	pOut->DrawPlayer(GetCell()->GetCellPosition(), getPlayerNum(), cellColor);

}


// ====== Game Functions ======

Attack* Player::ReadAttack(Grid* pGrid) const {


		pGrid->GetOutput()->PrintMessage("Choose Attack Number : Ice(0), Fire(1), Poison(2), Lightinig(3)");
		int AttackID = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		if (AttackID < 0 && AttackID > 3) {
			pGrid->PrintErrorMessage("Unvalid Attack, Click To Continue ...");
			return NULL;
		}

		Attack* attack;

		switch (AttackID) {
		case 0:
			attack = new IceAttack(pGrid);
			break;
		case 1:
			attack = new FireAttack(pGrid);
			break;
		case 2:
			attack = new PoisonAttack(pGrid);
			break;
		case 3:
			attack = new LightningAttack(pGrid);
			break;
		}
		return attack;
}

void Player::Move(Grid* pGrid, int diceNumber)
{

	///DONE: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	// 2- For Attack Check if Burned OR Poisoned and apply the effect
	if (Burned) {
		SetWallet(GetWallet() - AMOUNT_OF_COINS_LOSS); //Decrease wallet by Amount Constant and definitaion in FireAttack Header File
		Burned--;
	}
	if (Poisoned) {
		diceNumber -= AMOUNT_OF_DICE_LOSS; //Decrease Dice by Amount Constant and definitaion in PoisonAttack Header File
		Poisoned--;
	}

	// 3-1 Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == MAX_TURNS)
	{
		turnCount = 0;

		//3-2 Check If He Need To Attack or increase Wallet
		pGrid->GetOutput()->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
		string WalletORAttack = pGrid->GetInput()->GetSrting(pGrid->GetOutput());
		if (WalletORAttack[0] == 'y') {
			Attack* attack = ReadAttack(pGrid);
			if (attack) {
				bool added = addAttack(attack);
				if (added && attack->Execute()) { return; }
				else {
					pGrid->PrintErrorMessage("Unvalid Attack, Click To Continue ...");
					delete attack;
					attackCount--;
				}
					
			}
		}
		pGrid->GetOutput()->ClearStatusBar();
		wallet = wallet + INCRESMENT_MULTIPLY * diceNumber; //increase wallet

		if (turnsToPlay != 0)  turnsToPlay--; // check if we need to decrease turns to play to become zero
		return;
	}

	//3-2 Check if we need to decrease turns to play to become zero to Play
	if (turnsToPlay != 0) { turnsToPlay--; return; } // Decrease And End The Function

	//3-3 Check if Player Has Money In Wallet To Play
	if (GetWallet() <= 0) return; 

	//4- Increase StepCount and set JustRolledDice
	stepCount += diceNumber;
	justRolledDiceNum = diceNumber;

	//5-1 Check if stepCount Reach #100 (win)
	if (stepCount == NumHorizontalCells * NumVerticalCells + 1) {
		//5-2 update Player Cell to 99
		pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(NumHorizontalCells * NumVerticalCells));
		//5-3 Print Proper Message
		pGrid->PrintErrorMessage("Congrats, _Player_" + to_string(getPlayerNum()) + "_ You Win, Click To Continue ...");
		//5-4 set EndGame to True
		pGrid->SetEndGame(true);
	}
	//6-1 Check if stepCount More Than #100 (Do No Thing But Return StepCount)
	else if (stepCount > NumHorizontalCells * NumVerticalCells + 1) {
		stepCount -= diceNumber;
		return;
	}
	//7-1 if in the grid Normally Play
	else {
		//7-2 Add JustRolled Dice To Cell Number
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(justRolledDiceNum);

		//7-3 Check If position is valid Cell
		if (pos.IsValidCell()){
			pGrid->UpdatePlayerCell(this, pos); //Update Player Cell

			//Apply The Game Object
			GameObject* obj = pCell->GetGameObject();
			if (obj != NULL)
				obj->Apply(pGrid, this);
		}
		else {
			stepCount -= justRolledDiceNum;//make sure if not move to return step count to it's Normal
		}
	}
	
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
