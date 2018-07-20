#pragma once
#include "Board.h"
//using namespace std;
class Player{

public:
    //Player();
    virtual const Coordinate play(const Board& board) = 0;
    virtual const string name() const = 0;
    char myChar;
    void setChar(char ch){ this->myChar = ch;};
    char getChar(){ return myChar;};
};