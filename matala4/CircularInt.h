#include <iostream>
using namespace std;


int modulu(int x,int y);
class CircularInt{
int lowNum;
int highNum;
int hour;
public:
CircularInt(int x,int y);

friend ostream& operator<<(ostream& os, const CircularInt& circularInt);
friend CircularInt& operator+=(CircularInt& x ,int a);
friend CircularInt& operator-=(CircularInt& x ,int a);
friend CircularInt& operator++(CircularInt &b,int);
friend CircularInt& operator--(CircularInt &x,int);
friend int operator-(CircularInt& x);
friend CircularInt& operator-(int num,CircularInt& x);
friend int operator+(CircularInt& x,CircularInt& y);
friend CircularInt& operator+(CircularInt& y, int x);
friend CircularInt& operator*=(CircularInt& x,int num);
friend int operator/(CircularInt& x,int y);
};
