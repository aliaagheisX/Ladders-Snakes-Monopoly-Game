#include "PoisonAttack.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
PoisonAttack::PoisonAttack(Grid* pGrid): Attack(pGrid)
{
}

bool PoisonAttack::ReadAttackParameters()
{

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


bool PoisonAttack::Execute()
{
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
		pGrid->PrintErrorMessage("This Is Unvalid Player, Click To Continue ...");
		return false;
	}

	//set Player To Burn
	pPlayer->setPoison(MAX_TURNS_TO_POISON);
	return true;
}

bool PoisonAttack::CompareAttackType(Attack* attack) const {
	if (dynamic_cast<PoisonAttack*>(attack))
		return true;
	else return false;
}


PoisonAttack::~PoisonAttack()
{
}
