#pragma once

#include "Action.h"

class SwitchToDesignMode : public Action
{
	

public:

	SwitchToDesignMode(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); 

	virtual void Execute(); 


	virtual ~SwitchToDesignMode(); // Virtual Destructor

};

