#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

/* Dor Levi 203288139*/
/*Yarden Mizrahi 311332183*/

class Player {
private:
	string name; // name;
	int numOfCards;// num_of_cards;
	int numOfPlayer; //Player number
	vector<Card> cards;// container of cards
	void setName();
	bool checkCard(int);

public:
	Card myLastTurn;

	Player(const int, int);// constructor
	Player(const Player& other);
	bool play(const Card&);
	int getnumOfCards();
	string getName();
	void showCard();
	void addCard();
	Card getCard(const Card&);
	Player& operator=(const Player& other);
};
#endif



