

#include <vector>
#include <iostream>
using namespace std;




int lastId = 0;
 int counter=0;



class Member{
    public:
vector <Member> _followers;
vector <Member> _following;
public:
int ID;
int _numFollower,_numFollowing;
static int count();
void follow(Member &name);
void unfollow(Member &name);
Member(){
_numFollower=0;
_numFollowing=0;
ID=lastId+1;
lastId++;
counter+=1;
}
};



 int Member::count()
{
return counter;
}


void Member::follow(Member &name){
_following.push_back(name);
name._followers.push_back(*this);
_numFollowing+=1;
name._numFollower+=1;



}

void Member::unfollow(Member &name){
for(int i=0;i<this->_following.size();i++){
    if(name.ID==this->_following.at(i).ID){
        this->_following.erase(this->_following.begin()+i);   
        this->_numFollowing-=1;
        name._numFollower-=1;
        for(int j=0;j<name._followers.size();j++){
            if(this->ID==name._followers.at(j).ID){
            name._followers.erase(name._followers.begin()+j); 
                 }   
            }
        }
    }
}


int main(){
Member ser;
Member dor;
Member xx;
ser.follow(xx);
ser.follow(dor);
//ser.unfollow(dor);
cout<<dor._followers.size()<<endl;

return 0;
};