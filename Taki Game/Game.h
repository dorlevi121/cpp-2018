#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"

/* Dor Levi 203288139*/
/*Yarden Mizrahi 311332183*/

class Game {
private:
	int numOfPlayers; //number of players
	int numOfCards; //number of cards
	int numOfTurns;
	int rounds; //number of rounds game
	bool isWin; //if some player win then wim = true
	Card currentCard;
	vector<Player> players; //Vector of all the game player
	void initGame();
	void turn(Card&, int&);

public:
	Game(); //constructor
	~Game(); //Distructor
	Game(const Game& other);
	Game& operator=(const Game& other);
	void start();
};
#endif
