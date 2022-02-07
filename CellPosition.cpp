#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v >= NumVerticalCells || v < 0) { return false; }
	
	vCell = v;

	return true; 
}

bool CellPosition::SetHCell(int h) 
{
	if (h >= NumHorizontalCells || h < 0) { return false; }

	hCell = h;

	return true;
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: validation
	if (vCell != -1 && hCell != -1)
		return true;
	return false;
	// Done 18/11/2021
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	///TODO: return cell number by position send it from object cellPosition
	if (cellPosition.IsValidCell())
		return (NumHorizontalCells *  (NumVerticalCells - cellPosition.VCell() - 1) + cellPosition.HCell() + 1);
	
	return -1;
	// Done 18/11/2021
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	cellNum--; // to make cellNem from 0 -> 98
	int h, v;
	if (cellNum >= NumHorizontalCells * NumVerticalCells || cellNum < 0)
	{
		h = v = -1;
	}
	else
	{
		 h = cellNum % 11;
		 v = NumVerticalCells - 1 - ((cellNum - h) / 11);
	}
	

	CellPosition position(v, h);

	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	int cellNum = GetCellNumFromPosition(*this) + addedNum;

	if (addedNum < 0 || cellNum > NumHorizontalCells * NumVerticalCells + 1|| cellNum < 1) return;

	(*this) = GetCellPositionFromNum(cellNum);

}