#include "SwitchToDesignMode.h"
#include "Output.h"
#include "Grid.h"


SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDesignMode::ReadActionParameters()
{
	// no need to read action parameter
}

void SwitchToDesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	pOut->CreateDesignModeToolBar();

	pGrid->resetGame();
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}
