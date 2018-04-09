
#include "Member.h"
#include <algorithm>
#include <iostream>
using namespace std;

//int Member::lastId = 0;
//int Member::counter = 0;

Member::Member(){
ID = counter++;
members.push_back(ID);
}

Member::~Member(){
    counter--;
    members.remove(this->ID);
}

int Member::numFollowers(){
return followers.size();
}

int Member::numFollowing(){
return following.size();
}

 int Member::count(){
return counter;
}

void Member::follow(Member &name){
    bool flag=true;
   for(int i=0; i<this->following.size();i++){
           if(this->following.at(i) == name.ID){
               flag = false;
    }
   }

    if(flag==true){    
this->following.push_back(name.ID);
name.followers.push_back(this->ID);
    }
}

void Member::unfollow(Member &name){
for(int i=0;i<this->following.size();i++){
    if(name.ID==this->following.at(i)){
        this->following.erase(this->following.begin()+i);   
    
        }
    }
  for(int j=0;j<name.followers.size();j++){
    if(this->ID==name.followers.at(j)){
      name.followers.erase(name.followers.begin()+j); 
                 }   
            }
}