
#include "Member.h"
#include <algorithm>
#include <iostream>
using namespace std;

int Member::counter = 0;

////Constructors////
Member::Member(){
	ID = ++counter;
}

////Destructor////
Member::~Member(){
    	counter--;
	
for_each(followers.begin(), followers.end(), [this](Member * other) { other->following.remove(this); });
for_each(following.begin(), following.end(), [this](Member * other) { other->followers.remove(this); });
}

////return number of followers////
int Member::numFollowers(){
return followers.size();
}

////return number of following////
int Member::numFollowing(){
return following.size();
}

////return number of members////
 int Member::count(){
return counter;
}

void Member::follow(Member& name){
	if (find(following.begin(), following.end(), &name) == following.end()) 
	{
		following.push_back(&name);
		name.followers.push_back(this);
	}
}

void Member::unfollow(Member& name){
	following.remove(&name);
	name.followers.remove(this);
}