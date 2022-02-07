#include "CutCardAction.h"
#include "CellPosition.h"
#include "Card.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();


	pGrid->GetOutput()->PrintMessage("You Request A Cut Card Please Click on Proper Cell ...");

	CellPosition sourceCardPos = pGrid->GetInput()->GetCellClicked();

	sourceCard = pGrid->HasCard(sourceCardPos);

	pGrid->GetOutput()->ClearStatusBar();
}

void CutCardAction::Execute()
{
	ReadActionParameters();

	if (sourceCard == NULL) {
		pManager->GetGrid()->PrintErrorMessage("Unvalid Cut Card, Click To Continue...");
		return;
	}

	pManager->GetGrid()->SetClipboard(sourceCard);

	pManager->GetGrid()->RemoveObjectFromCell(sourceCard->GetPosition(), false); //remove object without deleted = False -> as clipboad save it as pointer
}

CutCardAction::~CutCardAction()
{
}
