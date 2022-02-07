#ifndef H_GRID
#define H_GRID

#include "UI_Info.h"
#include "DEFS.h"
#include "GameObjectTypes.h"
#include "Input.h"
#include "Output.h"
#include "CellPosition.h"

// forward declarations (the includes are in the cpp)
class Cell;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Grid
{
	Output * pOut;   // A pointer to the Output object
	Input * pIn;     // A pointer to the Input object

	Cell * CellList[NumVerticalCells][NumHorizontalCells];  // An array of "Pointers" to All Cells of the Grid Cells
															// We make it array of pointers not objects because
															// there are NO default constructor for class Cell

	Player* PlayerList[MaxPlayerCount]; // An array of "Pointers" to the Players of the Game (MaxPlayerCount Players)
	int currPlayerNumber;   // The player number that has the turn to play 
							// currPlayerNumber is: from 0 to MaxPlayerCount - 1

	Card * Clipboard;	   // This is used in copy/cut/paste card (should be set in copy/cut and got in paste)

	bool endGame;	       // A boolean indicating if the Game is ended or not (a player reaches the end cell of the grid or not)

public:

	Grid(Input * pIn, Output * pOut);	  // Gives the Grid a Pointer to the Output Object and the Input Object
										  // and makes any needed initializations

	// ========= Adding or Removing GameObjects to Cells =========

	bool AddObjectToCell(GameObject * pNewObject);		 // Adds a GameObject to the Cell of its "position" data member
	                                                     // only if the Cell does NOT already contain an object, 
	                                                     // otherwise return false and don't add

	void RemoveObjectFromCell(const CellPosition & pos, bool Deleted = true); // Removes the GameObject of the Cell of the passed "position"
																		   	  // Pass Deleted to make that we need to deleted it 
																			  // As In Cut Card We Use Remove Object Without Deleted It 
						
	void UpdatePlayerCell(Player * player, const CellPosition & newPosition); // Update the player's pCell with the CellList's Cell pointer of the "newPosition",
	                                                                          // Clears the player's circle from the previous cell
	    																	  // and  Draws it in the new cell
	
	// ========= Setters and Getters Functions =========

	Input * GetInput() const;	// Gets a Pointer to the Input
	Output * GetOutput() const; // Gets a Pointer to the Output 

	void SetClipboard(Card * card);  // A setter to be used in copy/cut (in order NOT to break class responsibilities)
	Card * GetClipboard() const;	 // A getter to be used in paste (in order NOT to break class responsibilities)

	void SetEndGame(bool endGame);	 // A setter for endGame data member
	bool GetEndGame() const;		 // A getter for endGame data member

	void AdvanceCurrentPlayer();     // Increments the currPlayerNum and if reaches MaxPlayerCount reset to 0 (using %)

	///DONE: add any needed setter/getter "EXCEPT" ANY setters or getters of "CellList" or "PlayerList" (Forbidden for class Responsibilities)

	// ========= Other Getters =========
	
	Player * GetCurrentPlayer() const;	// Gets a Pointer to the Current Player	                                    
	Ladder * GetNextLadder(const CellPosition & position);  // Gets a Pointer to the first Ladder after the passed "position"
	
	
	bool IsOverlapping(GameObject* newObj) const; // Gets if the new Object is overlapping with any thing

	Ladder* HasLadder(const CellPosition& pos) const; //Gets if the Cell in CellPosition (pos) have and Ladder
	Snake* HasSnake(const CellPosition& pos) const;   //Gets if the Cell in CellPosition (pos) have and Snake
	Card* HasCard(const CellPosition& pos) const;     //Gets if the Cell in CellPosition (pos) have and card
	
	int getCountOFLadders() const; //Gets The Count of Ladders In Grid
	int getCountOFSnakes() const;  //Gets The Count of Snakes In Grid
	int getCountOFCards() const;   //Gets The Count of Cards In Grid

	Player* getPoorestPlayer() const;    //Get The Poorest Player Who Has Less Money in His Wallet
	Player* getNextPlayer(Player*) const;//Get The Next Player In Grid To The Passed Player
	Player* getPlayerFromNum(int) const;//Get The Player In PlayerList From Number

	// ========= User Interface Functions =========

	void UpdateInterface() const;		// It Updates the Grid according to the last state of the game
	                                    // In Design mode, it draws all cells/cards THEN all ladders/snakes THEN all players
	                                    // In Play mode, it only draws the player's info on the right side of the toolbar
	                                    // Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
	                                    //       and the cards/snakes/ladders positions do NOT change already in Play Mode

	void PrintErrorMessage(string msg); // Prints an error message on statusbar, Waits for mouse click then clears statusbar
									    // We added this function once here because it is used many times by other classes
	

	void SaveAll(std::ofstream& OutFile, GameObjectsType OBJ); //Loop Through All Cells In Grid
															   //And Call GameObject::Save() if exsist

	void resetGame(); // Reset All Game in PlayMode To Start New Game
	
	void ClearAll(); // Delete All Objects In Grid Used In Open Grid

	~Grid(); // A destructor for any needed deallcations
};

#endif