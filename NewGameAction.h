#pragma once

#include "Action.h"

class NewGameAction : public Action
{
public:
	NewGameAction(ApplicationManager* pApp);  // Constructor

// ============ Virtual Functions ============

	virtual void ReadActionParameters(); //Doesn't Read Any Parameters


	virtual void Execute();
	//1-reset player
	//	1-1 return all players to zero position
	//  1-2 reset there wallet to zero



	virtual ~NewGameAction();
};

