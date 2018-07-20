#include <iostream>
#include "Board.h"
//#include "ObjBoard.hpp"

using namespace std;

////////// constructors and destructor ////////

Board::Board(int size){
    makeBoard(size);
    bildBoard();
}

Board::Board(const Board& bo){
    makeBoard(bo.sizeOfBoard);

    for(int i = 0; i < bo.sizeOfBoard; i++)
        for(int j = 0; j < bo.sizeOfBoard; j++)
            this->matBoard[i][j] = bo.matBoard[i][j];
}

Board::Board()
{
	this->sizeOfBoard=0;
	this->matBoard=NULL;
}


Board::~Board(){
	free();
}
//this code from: https://github.com/GeekCSA/Cpp-assignment/blob/master/Board.cpp
void Board::free(){
    for(int i = 0; i < this->sizeOfBoard; i++){
        delete[] this->matBoard[i];
    }
    delete[] this->matBoard;
}

//////// Bild Matrix ////////

void Board::makeBoard(int size){
    this->sizeOfBoard = size;
    matBoard = new ObjBoard*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++)
        matBoard[i] = new ObjBoard[sizeOfBoard];
}

void Board::bildBoard(){
    for(int i = 0; i<sizeOfBoard; i++){
        for(int j = 0; j < sizeOfBoard; j++){
            matBoard[i][j] = ObjBoard(i,j);
        }
        cout << endl;
    }
}

///////// operator << //////////

ostream& operator<<(ostream& os, const Board& Board) {
    	for(int i = 0; i < Board.sizeOfBoard; i++){
		    for(int j = 0; j < Board.sizeOfBoard; j++)
                  os << Board.matBoard[i][j];
		os << "" << endl;
	}
    return os;
    }

///////////// operators [] ///////////

char Board::operator[](const Coordinate& obj) const{
    int x = obj.x;
    int y = obj.y;
    if(x >= this->sizeOfBoard || y >= this->sizeOfBoard){
          IllegalCoordinateException ex;
              ex.setA(x); ex.setB(y);
                throw ex;
    }

    else
    return matBoard[x][y].getAT();
}

ObjBoard& Board::operator[](const Coordinate& obj){
    int x = obj.x;
    int y = obj.y;
    if(x >= this->sizeOfBoard || y >= this->sizeOfBoard){
          IllegalCoordinateException ex;
              ex.setA(x); ex.setB(y);
                throw ex;
    }
    else 
    return this->matBoard[x][y];
}

/////////// operators = ///////////

Board& Board::operator=(const char c){
if(c=='X'||c=='O'||c=='.') {
		for (int i = 0; i < sizeOfBoard; i++) {
			for (int j = 0; j < sizeOfBoard; j++) {
				this->matBoard[i][j] = c;
			}
            		}
	}    else{
        IllegalCharException ex;
        ex.setC(c);
        throw ex;
    }
    
    return *this;
}

Board& Board::operator=(const Board & bo){
    if(bo.sizeOfBoard != this->sizeOfBoard){
        free();
        makeBoard(bo.sizeOfBoard);
    }

    for(int i = 0; i < bo.sizeOfBoard; i++)
        for( int j = 0; j < bo.sizeOfBoard; j++)
            this->matBoard[i][j] = bo.matBoard[i][j];

            return *this;
}

// char Board::operator=(const ObjBoard& ob){
//     int x = ob.getX();
//     int y = ob.getY();
//     char a = this->matBoard[x][y].getAT();
//     return a;
// }


////// get size ///////
uint Board::size() const{
	return sizeOfBoard;
}