#include "Snake.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	//check validation
	if (endCellPos.VCell() > this->position.VCell() && endCellPos.HCell() == this->position.HCell())
		this->endCellPos = endCellPos;

}
Snake::Snake() { //Default Constructor used in OpenGrid
	this->endCellPos = CellPosition::GetCellPositionFromNum(1);
}




void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position,endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Print a Proper Message
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");

	// 2- Apply the Snakes's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


bool Snake::IsOverlapping(const Grid* pGrid,GameObject* newObj) const
{
	// 1- check if newObj isn't NULL Pointer
	// 2- check if newObj is Ladder By Calling the Grid Function in Grid which Call HasSnake in Cell
	if (newObj && pGrid->HasSnake(newObj->GetPosition()))
	{
		//3-check overlapping 
		// (a.start <= b.end && b.start <= a.end) in simple words
		// a.Hcell = b.Hcell
		// using static cast to convert GameObject newObj to snake --->>> to call getEndPos
		if (newObj->GetPosition().VCell() <= this->endCellPos.VCell() && this->GetPosition().VCell() <= static_cast<Snake*>(newObj)->GetEndPosition().VCell() && newObj->GetPosition().HCell() == this->GetPosition().HCell())
			return true;
	}
	return false;

}

void Snake::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_SNAKE) // check if Obj is Snake
	{
		GameObject::Save(OutFile, Obj); //print the start Position of Snake 
		OutFile << GetEndPosition().GetCellNum() << '\n'; // print the The end Positon of Snake
	}
}


GameObject* Snake::Load(ifstream& InFile) {

	// 1-read the start position and set it by calling the function in gameObject
	GameObject::Load(InFile); 


	//2-read the end Position
	int  endPosCellNum;
	InFile >> endPosCellNum;

	//3-set the end Position
	endCellPos = CellPosition::GetCellPositionFromNum(endPosCellNum);
	
	return this;
}


Snake::~Snake()
{
}