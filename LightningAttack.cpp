#include "LightningAttack.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Player.h"
LightningAttack::LightningAttack(Grid* pGrid) : Attack(pGrid) {

}

bool LightningAttack::Execute() {

	//get pointers the choosen player
	Player* pPlayer;

	//loop through players from nextPlayer
	//using getCurrPlayer And AdvancePlayer
	//Decrease their wallet by constant define in header file
	pGrid->AdvanceCurrentPlayer();
	for (int i = 1; i < MaxPlayerCount; i++) {

		pPlayer = pGrid->GetCurrentPlayer();

		pPlayer->SetWallet(pPlayer->GetWallet() - AMOUNT_OF_COINS_LOSS_LIGHT);

		pGrid->AdvanceCurrentPlayer();
	}
	return true;
}

bool LightningAttack::CompareAttackType(Attack* attack) const {
	if (dynamic_cast<LightningAttack*>(attack))
		return true;
	else return false;
}


LightningAttack::~LightningAttack() {

}