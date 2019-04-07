#include "Player.h"
/* Dor Levi 203288139*/
/*Yarden Mizrahi 311332183*/
Player::Player(const int numberPlayer, int numOfCards){
    this->numOfCards = numOfCards;
    for(size_t i = 0; i < numOfCards; i++){
        Card temp_card = (Card::generate_card());
        cards.push_back((temp_card));
    }
    this->numOfPlayer = numberPlayer;
    setName();
}


Player::Player(const Player& other){
    *this = other;
}


Player& Player::operator=(const Player& other){

    this->name = other.name;
    this->numOfCards = other.numOfCards;
    for (size_t i = 0; i < numOfCards; i++) {
      Card temp = other.cards.at(i);
      cards.push_back(temp);
    }
  return *this;

}

void Player::setName(){
    cout << "Player number " <<numOfPlayer << " name?" <<endl;
    cin >> this->name; 
    while(name.empty()){
        cout << "Yoy didn't enter name" << endl;
        cout << "Player number " <<numOfPlayer << " name?" <<endl; 
        cin >> this->name;
    }  
}


int Player::getnumOfCards(){
    return numOfCards;
}

string Player::getName(){
    return name;
}

void Player::showCard(){
    cout << name << ", your turn-" <<endl;
     cout << "Your cards: ";
    for(size_t i = 0; i < cards.size(); i++)
		std::cout << "(" << i + 1 << ")" << (cards.at(i)) << ' ';
         
    
    cout << '\n';
}

void Player::addCard(){
  Card temp = temp.generate_card();
  this->cards.push_back(temp);
  numOfCards++;
}

bool Player::checkCard(int cardNumber){
    if(cardNumber < 0)
        exit(0);
    else if(cardNumber > numOfCards || cardNumber == 0){
        addCard();
        return false;
    }
    return true;
}

bool Player::play(const Card& cr){
    int cardNumber = 0;
    showCard();
    cin >> cardNumber; 
    if(!checkCard(cardNumber))
        return false;
    cardNumber--; 

   if(cr.is_legal(cards.at(cardNumber))){
       myLastTurn = cards.at(cardNumber);
        cards.erase(cards.begin()+cardNumber);             
       numOfCards--;
       return true;
    }
   else{
       while(!cr.is_legal(cards.at(cardNumber))){
           cout << "You can't put " << cards.at(cardNumber) << " on " << cr <<endl;
           cin >> cardNumber; 
          if(!checkCard(cardNumber))
                return false;
          cardNumber--; 
       }
        myLastTurn = cards.at(cardNumber);
       cards.erase(cards.begin()+cardNumber);       
       numOfCards--;
        return true;
   }
return true;
}