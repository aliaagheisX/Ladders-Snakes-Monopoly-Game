#include "SwitchToPlayMode.h"
#include "Output.h"
#include "Grid.h"


SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToPlayMode::ReadActionParameters()
{
	// no need to read action parameter
}

void SwitchToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	pOut->CreatePlayModeToolBar();

	pGrid->resetGame();
}

SwitchToPlayMode::~SwitchToPlayMode()
{
}
