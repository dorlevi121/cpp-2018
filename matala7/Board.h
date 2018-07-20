#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "ObjBoard.h"
#include "Coordinate.h"
#pragma once

using namespace std;

class Board{
    
private:
    int sizeOfBoard;
    ObjBoard** matBoard;

    void makeBoard(int);
    void bildBoard();
    void free();


public:
     Board(int);
     Board(const Board&);
     Board();
     ~Board();

    friend ostream& operator<<(ostream& os, const Board& Board);

    char operator[](const Coordinate&) const;
    ObjBoard& operator[](const Coordinate&);

    Board& operator=(const Board&);
    Board& operator=(const char);
    //char operator=(const ObjBoard&);

    uint size() const;

};


class IllegalCoordinateException : public exception{

    int a , b;

public:
    void setA(int a){
        this->a = a;
    }
    void setB(int b){
        this->b = b;
    }

    string theCoordinate() const{
        return to_string(this->a)+","+to_string(this->b);
    }
};

class IllegalCharException : public exception{

    char ch;

public:
    void setC(char ch){
        this->ch = ch;
    }

    char theChar() const{
        return ch;
    }
};