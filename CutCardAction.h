#pragma once
#include "Action.h"
class CutCardAction : public Action
{
	Card* sourceCard;
public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads and check source cell

	virtual void Execute(); // set the clipboard


	virtual ~CutCardAction(); // Virtual Destructor
};

