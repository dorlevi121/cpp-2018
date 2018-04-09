#pragma once
#include <vector>
#include <iostream>
#include <list>

using namespace std;
static list<int> members; 
static int counter = 0;

class Member{

vector <int> followers;
vector <int> following;
int ID;


public:
Member();
~Member();
static int count();
void follow(Member& name);
void unfollow(Member& name);
int numFollowers();
int numFollowing();

};