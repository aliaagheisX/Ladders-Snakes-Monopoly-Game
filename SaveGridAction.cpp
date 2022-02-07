#include<fstream>

#include<string>
#include "SaveGridAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp) {} // Constructor

// ============ Action Functions ============

void SaveGridAction::ReadActionParameters() {
	//READ THE FILE NAME
	
	Grid* pGrid = pManager->GetGrid(); //get pointer to grid


	//1-print proper message 
	pGrid->GetOutput()->PrintMessage("You Request To Save Game Please Enter File Name");

	//get file name
	fileName = pGrid->GetInput()->GetSrting(pGrid->GetOutput());

	pGrid->GetOutput()->ClearStatusBar();

}

void SaveGridAction::Execute() {
	ReadActionParameters();
	//1-get pointer to grid
	Grid* pGrid = pManager->GetGrid();

	
	//2-open file
	std::ofstream file;
	
	
	file.open("Grids/" + fileName + ".txt");

	//4-1 calling getCountofLadder which is  function in grid
	//		Grid Loop through all cells
	//		add check using HasLadder
	//4-2 calling saveAll in grid and pass the Objects Types
	// 
	//				Ladders
	file << pGrid->getCountOFLadders() << '\n';

	pGrid->SaveAll(file, OBJ_LADDER);

	//				Snakes
	file << pGrid->getCountOFSnakes() << '\n';
	pGrid->SaveAll(file, OBJ_SNAKE);

	//				Cards
	file << pGrid->getCountOFCards() << '\n';
	for(int i = OBJ_CARD_1;i < NUMBER_OF_CARDS;i++){
		pGrid->SaveAll(file, (GameObjectsType)i);
	}

	StationCard::EndPrint(); //end print in stations card so it will print parameters in next file save

	file.close();

}
SaveGridAction::~SaveGridAction() {} // Virtual Destructor