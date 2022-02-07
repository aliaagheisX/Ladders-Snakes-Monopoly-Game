#pragma once
#include "Action.h"
class DeleteGameObjectAction : public Action
{
	CellPosition cellPosition; // 2- cell position of the Object to delete

	// Note: These parameters should be read in ReadActionParameters()

public:
	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads deleteGameObject action parameters (cellPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number

	virtual ~DeleteGameObjectAction(); // A Virtual Destructor
};

