#include "Ladder.h"
#include "Output.h"
#include "Player.h"
#include "Input.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{

	//check validation
	if(endCellPos.VCell() < this->position.VCell() && endCellPos.HCell() == this->position.HCell())
		this->endCellPos = endCellPos;

}
Ladder::Ladder() {
	this->endCellPos = CellPosition::GetCellPositionFromNum(1); //Default Constructor used in Open Grid

}


void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///DONE: Implement this function as mentioned in the guideline steps (numbered below) below

	// 1- Print a Proper Message
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, GetEndPosition());
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverlapping(const Grid* pGrid, GameObject* newObj) const
{	
	// 1- check if newObj isn't NULL Pointer
	// 2- check if newObj is Ladder By Calling the Grid Function in Grid which Call HasLadder in Cell
	if (newObj && pGrid->HasLadder(newObj->GetPosition()))
	{
		//3-check overlapping 
		// (a.start >= b.end && b.start >= a.end) in simple words
		// a.Hcell = b.Hcell
		// using static cast to convert GameObject newObj to Ladder --->>> to call getEndPos
		if (newObj->GetPosition().VCell() >= this->endCellPos.VCell() && this->GetPosition().VCell() >= static_cast<Ladder*>(newObj)->GetEndPosition().VCell() && newObj->GetPosition().HCell() == this->GetPosition().HCell())
			return true;//if all conditions true  then return true
	}
	return false;

}
void Ladder::Save(ofstream& OutFile, GameObjectsType Obj) const {
	if (Obj == OBJ_LADDER) // check if Obj is Ladder
	{ 
		GameObject::Save(OutFile, Obj); //print the start Position of Ladder 
		OutFile << GetEndPosition().GetCellNum() << '\n'; // print the The end Positon of ladder
	}
}

GameObject* Ladder::Load(ifstream& InFile) {

	GameObject::Load(InFile);

	int  endPosCellNum;

	InFile >>  endPosCellNum; //read

	endCellPos = CellPosition::GetCellPositionFromNum(endPosCellNum);
	return this;
}


Ladder::~Ladder()
{
}
