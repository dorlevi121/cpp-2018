#include <iostream>
#include "CircularInt.h"
using namespace std;


int  modulu(int x,int y){
   int shalem = (x/y);
   return x-shalem*y; 
}

CircularInt::CircularInt(int x,int y){
this->lowNum=x;
this->highNum=y;
this->hour=y;
}

ostream& operator<<(ostream& os, const CircularInt& circularInt) {
    os << circularInt.lowNum;
    return os;
}

   

CircularInt& operator-=(CircularInt& x ,int a){
       x.lowNum=x.lowNum+a;
       if(x.lowNum>x.highNum){
       x.lowNum=modulu(x.lowNum,x.highNum);

   }
       return x;
   }


   CircularInt& operator+=(CircularInt& x ,int a){
       x.lowNum=x.lowNum+a;
       if(x.lowNum>x.highNum){
       x.lowNum=modulu(x.lowNum,x.highNum);

   }
       return x;
   }

CircularInt& operator++(CircularInt &b,int){

b.lowNum+=1;
if(b.lowNum>b.highNum){
       b.lowNum=modulu(b.lowNum,b.highNum);

   }
return b;

}
CircularInt& operator--(CircularInt& x,int) {
   
   x.lowNum=x.lowNum-1;
   if(x.lowNum>x.highNum){
      x.lowNum=modulu(x.lowNum,x.highNum);
   }
}
int operator-(CircularInt& x){
return x.hour-x.lowNum;
}
CircularInt& operator-(int num,CircularInt& x){
//x.lowNum=x.hour-modulu(num,x.lowNum);
x.lowNum=x.hour+(num-x.lowNum);
if(x.lowNum>x.highNum){
x.lowNum=x.lowNum-x.highNum;
}
return x;
}
int operator+(CircularInt& x,CircularInt& y){
int temp=x.lowNum+x.lowNum;
if(temp>x.hour){
return modulu(temp,x.hour);
}else return temp ;

}

CircularInt& operator*=(CircularInt& x,int num){
x.lowNum=(x.lowNum)*num;
if(x.lowNum>x.hour){
x.lowNum=modulu(x.lowNum,x.hour);
return x;
}
else return x ;
}

int operator/(CircularInt& x,int y){
if(x.lowNum%y==0){
return x.lowNum/y;

}else{
throw string( "Cant be divided" );

}

}

   CircularInt& operator+(CircularInt& x ,int a){
       x.lowNum = x.lowNum + a;
       if(x.lowNum > x.highNum){
       x.lowNum=modulu(x.lowNum,x.highNum);
   }
       return x;
   }