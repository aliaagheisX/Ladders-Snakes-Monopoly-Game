#ifndef H_ICE_ATTACK
#define H_ICE_ATTACK

#include "Attack.h"

class IceAttack : public Attack
{
	int playerNumber;
public:

	IceAttack(Grid* pGrid);  // Constructor

	// ============ Virtual Functions ============

	virtual bool ReadAttackParameters(); // Reads parameters required for Attack to execute 
										 // Read the Player Number That will prevent the next rolling

	virtual bool Execute();  // Executes Attack
							 // by prevent player rolling the Next Turn

	virtual bool CompareAttackType(Attack* attack) const;

	virtual ~IceAttack();  // Virtual Destructor
};

#endif

