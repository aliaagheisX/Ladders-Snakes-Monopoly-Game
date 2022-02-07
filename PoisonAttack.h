
#include "Attack.h"

const int MAX_TURNS_TO_POISON = 5;
const int AMOUNT_OF_DICE_LOSS = 1;
class PoisonAttack : public Attack
{
	int playerNumber;

public:

	PoisonAttack(Grid* pGrid);  // Constructor

	// ============ Virtual Functions ============

	virtual bool ReadAttackParameters(); // Reads parameters required for Attack to execute 
										 // Read the Player Number That will Burn

	virtual bool Execute();  // Executes Attack
							 // by call Player Burn

	virtual bool CompareAttackType(Attack* attack) const;

	virtual ~PoisonAttack();  // Virtual Destructor
};