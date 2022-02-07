#include "IceAttack.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
IceAttack::IceAttack(Grid* pGrid) : Attack(pGrid) {

}

bool IceAttack::ReadAttackParameters() {
	//get pointers to Grid

	//print proper message
	pGrid->GetOutput()->PrintMessage("Enter Player Number ...");

	//wait for input
	playerNumber = pGrid->GetInput()->GetInteger(pGrid->GetOutput());

	//clear status bar
	pGrid->GetOutput()->ClearStatusBar();

	//Check The Validation
	if (playerNumber < 0 || playerNumber >= MaxPlayerCount) {
		// print proper message
		pGrid->PrintErrorMessage("This Is Unvalid Player, Click To Continue");
		return false;
	}

	return true; //return true if everthing okay
}

bool IceAttack::Execute() {
	//Call Read Parameters
	bool readParameters = ReadAttackParameters();
	
	//if there's problem then end and return false
	if (!readParameters)
		return false;

	//get pointers to the choosen player
	Player* pPlayer = pGrid->getPlayerFromNum(playerNumber);

	//Make Sure Everthing Okay
	if (pPlayer == NULL) {
		//print proper message and return false
		pGrid->PrintErrorMessage("This Is Unvalid Player, Click To Continue");
		return false;
	}

	//set turns to play to One
	pPlayer->SetTurnsToPlay(1);
	return true;
}

bool IceAttack::CompareAttackType(Attack* attack) const {
	if (dynamic_cast<IceAttack*>(attack))
		return true;
	else return false;
}


IceAttack::~IceAttack() {

}