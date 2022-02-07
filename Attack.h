#ifndef H_ATTACK
#define H_ATTACK

#include "ApplicationManager.h"
#include "Cell.h"


class Attack
{
protected:

	Grid* pGrid;	// Attacks needs ApplicationManager to do their job

public:

	Attack(Grid* pGrid);  // Constructor

	// ============ Virtual Functions ============

	virtual bool ReadAttackParameters(); // Reads parameters required for Attack to execute 
										 // not pure virtual as some attacks doesn't need read Parameters
										 // bool to make sure that read Parameters are validated
										 // (code depends on attack type so virtual)

	virtual bool Execute() = 0;  // Executes Attack (code depends on action type so virtual)


	virtual bool CompareAttackType(Attack* attack) const = 0;

	virtual ~Attack();  // Virtual Destructor
};
#endif // !H_ATTACK


