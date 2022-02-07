#ifndef H_LIGHTNING_ATTACK
#define H_LIGHTNING_ATTACK

#include "Attack.h"

const int AMOUNT_OF_COINS_LOSS_LIGHT = 20;

class LightningAttack : public Attack
{
public:

	LightningAttack(Grid* pGrid);  // Constructor

	// ============ Virtual Functions ============

	virtual bool Execute();  // Executes Attack
							 // by Loop Around The Players 
							 //Using Grid AdvanceCurrPlayer
							 //And Decrease their Wallet

	virtual bool CompareAttackType(Attack* attack) const;


	virtual ~LightningAttack();  // Virtual Destructor
};

#endif