#pragma once
#include "Action.h"

class OpenGrid : public Action
{

	std::string fileName;

public:
	OpenGrid(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~OpenGrid();
};

