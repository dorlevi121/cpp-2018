#include <iostream>
#include <stdbool.h>

#include "ObjBoard.hpp"
#include "Board.h"

using namespace std;

ObjBoard::ObjBoard(){
    this->x = 0;
    this->y = 0;
    this->at = '.';
}

ObjBoard::ObjBoard(int i, int j){
    this->x = i;
    this->y = j;
    this-> at = '.';
    
}

ObjBoard::ObjBoard(char dot){
    this->at = dot;
}

ostream& operator<<(ostream& os, const ObjBoard& ob){
    return os << ob.getAT();
}

ObjBoard& ObjBoard::operator=(const char ch){
        this->at = ch;

    return *this;
}


ObjBoard::operator char() const {
	return getAT();
}

bool operator==(ObjBoard& s, char c)
{
	if(s.getAT()==c) return true;
	return false;
}

int ObjBoard::getX()const {
    return x;
}

int ObjBoard::getY() const {
    return y;
}

char ObjBoard::getAT() const {
    return at;
}