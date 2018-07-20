#include <iostream>
#pragma once

using namespace std;


class ObjBoard{

private:
    int x , y;
    char at;

public:
    friend ostream& operator<<(ostream& os, const ObjBoard&);

    ObjBoard& operator=(const char);
    operator char() const;
	friend bool operator==(ObjBoard&, char);


    ObjBoard();
    ObjBoard(int , int);
    ObjBoard(char);
    int getX() const;
    int getY() const;
    char getAT() const;


};