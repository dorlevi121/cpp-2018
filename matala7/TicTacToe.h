
#pragma once

#include "Board.h"
#include "Player.h"


class TicTacToe{

private:
uint sizeBoard;
Board board_table;
Player* iWin;

bool checkCoor(const Coordinate& ) const;
bool boardFull();


public:
TicTacToe();
TicTacToe(uint );
void play(Player& , Player&); //Running a game between 2 players(first x , second o)
Board board()const; //Print the game board at the end of the game
Player& winner() const; //return the einner player
bool isWin(Player& );
void clearBoard();


};