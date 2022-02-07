#pragma once
#include "Action.h"
#include "Card.h"
#include "CellPosition.h"
class CopyCardAction : public Action
{
	Card* sourceCard;
public:

	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads and check source cell

	virtual void Execute(); // set the clipboard


	virtual ~CopyCardAction(); // Virtual Destructor
};

