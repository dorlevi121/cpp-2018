#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <fstream>
#include <chrono>
#include <vector>
#include "ObjBoard.hpp"

using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};


class Board{
    
public:
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

     string draw(int);

    friend ostream& operator<<(ostream& os, const Board& Board);
	friend istream& operator>>(std::istream& input, Board& board);

    char operator[](const ObjBoard&) const;
    ObjBoard& operator[](const ObjBoard&);

    Board& operator=(const Board&);
    Board& operator=(const char);
    char operator=(const ObjBoard&);
   // ObjBoard& operator==(const char);


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