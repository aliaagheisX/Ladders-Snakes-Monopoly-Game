#ifndef GAME_OBJECT
#define GAME_OBJECT

#include<fstream>
#include "Grid.h"
#include "GameObjectTypes.h"

// Base Class for All Game Objects ( ladders, snakes and cards )
class GameObject
{

protected:

	CellPosition position; // The current cell position of the GameObject
	
public:

	GameObject(const CellPosition& pos); // Constructor for initializing data members
	GameObject(); 
	
	CellPosition GetPosition() const;     // A Getter for position

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
											     // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
	                                                       // (The effect depends on the GameObject type, so virtual)
	                                                       // For example, applying a ladder is by moving player up, and so on

	virtual bool IsOverlapping(const Grid* pGrid,GameObject* newObj) const; // we didn't make it pure virtual
																			// as Card didn't need to have overlapping

	
	virtual void Save(ofstream &OutFile, GameObjectsType Obj) const = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream &Infile, GameObjectsType Obj) = 0;	// Loads and Reads the GameObject parameters from the file


	virtual GameObject* Load(ifstream& InFile) = 0;

	virtual ~GameObject(); // Virtual destructor
};

#endif
