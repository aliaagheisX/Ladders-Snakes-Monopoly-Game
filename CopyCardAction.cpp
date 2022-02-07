#include "CopyCardAction.h"
#include "CellPosition.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();


	pGrid->GetOutput()->PrintMessage("You Request A Copy Card Please Click on Proper Cell ...");
		
	CellPosition sourceCardPos = pGrid->GetInput()->GetCellClicked();
	sourceCard = pGrid->HasCard(sourceCardPos);
	
	pGrid->GetOutput()->ClearStatusBar();
}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	
	if (sourceCard == NULL) {
		pManager->GetGrid()->PrintErrorMessage("Unvalid Copy Card, Click To Continue...");
		return;
	}
	
	pManager->GetGrid()->SetClipboard(sourceCard);
}

CopyCardAction::~CopyCardAction()
{
}
