#pragma once
#include <list>
#include <iostream>

using namespace std;

class Member {

private:
	static int counter; 
	int ID; 
	list<Member*> following; 
	list<Member*> followers; 

public:
	Member();
	~Member();
	void follow(Member &name);
	void unfollow(Member &name);
	int numFollowers();
	int numFollowing();
	static int count();
};