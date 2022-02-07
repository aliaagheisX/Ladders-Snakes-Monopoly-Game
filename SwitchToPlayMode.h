#pragma once

#include "Action.h"

class SwitchToPlayMode : public Action
{
	

public:

	SwitchToPlayMode(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); 

	virtual void Execute(); 


	virtual ~SwitchToPlayMode(); // Virtual Destructor

};

