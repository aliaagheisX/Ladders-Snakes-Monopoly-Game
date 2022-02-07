#pragma once
#include "Action.h"
#include "CellPosition.h"
class PasteCardAction : public Action
{
	CellPosition destinationCard;
public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads and check destination cell

	virtual void Execute(); // set the clipboard


	virtual ~PasteCardAction(); // Virtual Destructor
};

