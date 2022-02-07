#include "GameObject.h"

GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

GameObject::GameObject()
{
	position = CellPosition::GetCellPositionFromNum(1); // Sets Position
}

bool GameObject::IsOverlapping(const Grid* pGrid, GameObject* newObj) const {
	return true;//as default value which have no value actually in program
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

//print the start position of any object as it used in all objects
void GameObject::Save(ofstream& OutFile, GameObjectsType Obj) const {
	OutFile << GetPosition().GetCellNum() << ' ';
}


GameObject* GameObject::Load(ifstream& InFile) {
	int startPosCellNum;

	InFile >> startPosCellNum; //read

	position = CellPosition::GetCellNumFromPosition(startPosCellNum);
	return NULL;
}


GameObject::~GameObject()
{
}