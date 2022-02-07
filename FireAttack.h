#ifndef H_FIRE_ATTACK
#define H_FIRE_ATTACK

#include "Attack.h"

const int MAX_TURNS_TO_BURN = 5;
const int AMOUNT_OF_COINS_LOSS = 20;
class FireAttack : public Attack
{
	int playerNumber;
	
public:

	FireAttack(Grid* pGrid);  // Constructor

	// ============ Virtual Functions ============

	virtual bool ReadAttackParameters(); // Reads parameters required for Attack to execute 
										 // Read the Player Number That will Burn

	virtual bool Execute();  // Executes Attack
							 // by call Player Burn
	virtual bool CompareAttackType(Attack* attack) const;
	virtual ~FireAttack();  // Virtual Destructor
};

#endif


