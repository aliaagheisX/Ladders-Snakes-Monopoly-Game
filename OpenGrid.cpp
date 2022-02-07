#include "OpenGrid.h"
#include<fstream>

#include<string>
#include "Grid.h"
#include "Input.h"
#include "Output.h"

#include "Ladder.h"
#include "Snake.h"
#include "Card.h"

#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

OpenGrid::OpenGrid(ApplicationManager* pApp) :Action(pApp) {} // Constructor

// ============ Action Functions ============

void OpenGrid::ReadActionParameters() {
	//READ THE FILE NAME

	Grid* pGrid = pManager->GetGrid(); //get pointer to grid


	//1-print proper message 
	pGrid->GetOutput()->PrintMessage("You Request To Open Grid, Please Enter File Name");

	//get file name
	fileName = pGrid->GetInput()->GetSrting(pGrid->GetOutput());

	pGrid->GetOutput()->ClearStatusBar();

}

void OpenGrid::Execute() {
	ReadActionParameters();
	//1-get pointer to grid
	Grid* pGrid = pManager->GetGrid();


	//2-open file
	std::ifstream file;


	file.open("Grids/" + fileName + ".txt"); //open file

	if (!file.is_open()) return;//if not Open then close

	//4-1 calling getCountofLadder which is static function in ladder
	//4-2 calling saveAll in grid and pass the Objects Types

	GameObject* pObj;
	pManager->GetGrid()->ClearAll(); //clear grid Objects
	pManager->GetGrid()->resetGame();//reset all players


	//				Ladders
	int count;
	file >> count; //read count of ladders

	for (int i = 0; i < count; i++) {
		pObj = new Ladder(); // make empty project
		pObj = pObj->Load(file); // call load function in Ladder
		pManager->GetGrid()->AddObjectToCell(pObj); //added to grid
	}

	//				Snakes

	file >> count; //read count of snakes
	for (int i = 0; i < count; i++) {
		pObj = new Snake();
		pObj = pObj->Load(file);
		pManager->GetGrid()->AddObjectToCell(pObj);//added to grid
	}
	//				Card

	file >> count;
	for (int i = 0; i < count; i++) {
		pObj = new Card();// make empty project
		pObj = pObj->Load(file);// call load function in Snake
		pManager->GetGrid()->AddObjectToCell(pObj);//added to grid
	}


	StationCard::EndRead(); //end read in stations card so it will read parameters in next file Open
	file.close();

}
OpenGrid::~OpenGrid() {} // Virtual Destructor