#pragma once

#include "Grid.h"
#include "Cell.h"
#include "Attack.h"

const int MAX_TURNS = 3;// maximum tunrs that after it reset and increase wallet
const int INCRESMENT_MULTIPLY = 10;// this number multiplied by dice number in third turn and added to wallet
const int INITAL_WALLET = 100;//all players Start with this number in their wallet
const int NUMBER_OF_STATIONS = 3;//Number OF Card Stations in Cards
const int MAX_ATTACKS = 2;//Maximum unique special attacks can player have 
class StationCard;

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3z
	                       // it is used to indicate when to move and when to add to your wallet
	
	StationCard* stations[NUMBER_OF_STATIONS];//pointers to stations that Player Have
	int stationsCount;//Count of Stations that Player Have it reset to zero again at NewGame Action

	int turnsToPlay;//integer used in card 4, 8
					//if it equal zero the player can Move Freely
					//else it will decrease by 1 if the player->Move() Called
					///NOTE: the round which the wallet increase Still InCrease

	int Burned;		// used in attacks
						//set by default to 0
						//if one attack fire to this player 
						//it will decrease his wallet by 20 for [MAX turns]
						// MAX turns decide as constant in FireAttack Header File
						//isBurned count how many times to stop burn
	
	int Poisoned;		// used in attacks
						//set by default to 0
						//if one attack Poison to this player 
						//it will decrease his justRolledDice by One For [MAX turns]
						// MAX turns decide as constant in PoisonAttack Header File
						//isPoisned count how many times to stop be poisoned
	Attack * attacks[MAX_ATTACKS];	//stored the attack that player choose
							//Must Be Unique

	int attackCount;		//the count of attacks that player have
	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	void resetPlayer(Grid* pGrid, Cell* pCell); //reset the player to all the inital values

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	int getStepCount() const;		// A getter for the stepCount

	int getPlayerNum() const;		// A getter for the player number
	int setPlayerNum(int number);   // A setter for the player number
									// called at constructor to validate the playerNumber before set it

	int getJustRolledDice() const;  // A getter for the just rolled dice


	int getTurnsToPlay() const;     // A getter for the turnsToPlay
	void SetTurnsToPlay(int);       // A setter for the turnsToPlay
	
	
	// ====== Stations Functions ======

	void addStation(StationCard*);		// Add Station To Player stations
	void removeStation(StationCard*);   // Remove Station From Player stations
	StationCard* getExpensiveStation(); // Loop through stations the player Have and return the Most Expensive

	// ====== Attacks Functions ======
	void setBurn(int);
	void setPoison(int);

	bool addAttack(Attack *attack);

	Attack* ReadAttack(Grid * pGrid) const;

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell


	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)


};

