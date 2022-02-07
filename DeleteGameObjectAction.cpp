#include "DeleteGameObjectAction.h"

#include "GameObject.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	//1-get pointer to grid
	Grid* pGrid = pManager->GetGrid();

	pGrid->GetOutput()->PrintMessage("Click any Cell To Delete Object in it...");

	cellPosition = pGrid->GetInput()->GetCellClicked();

	pGrid->GetOutput()->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();


	Grid* pGrid = pManager->GetGrid();
	
	if (!cellPosition.IsValidCell()) {
		pGrid->PrintErrorMessage("Unvalid Cell Position, Click To Continue ...");
		return;
	}
	
	pGrid->RemoveObjectFromCell(cellPosition);
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}
