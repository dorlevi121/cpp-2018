#include "Game.h"
/* Dor Levi 203288139*/
/*Yarden Mizrahi 311332183*/
static string state = "PLUS1";

Game::Game(){
    numOfCards = 0;
    numOfPlayers = 0;
    numOfTurns = 0;
    rounds = 0;
    isWin = false;
    currentCard = Card().generate_card(); //Select the first card
}

Game::~Game(){
    this->players.clear();
}

Game::Game(const Game& other){
    this->numOfCards = other.numOfCards;
    this->numOfPlayers = other.numOfPlayers;
    this->numOfTurns = other.numOfTurns;
    this->currentCard = other.currentCard;
    for (size_t i = 0; i < numOfPlayers; i++) {
      Player temp = other.players.at(i);
      players.push_back(temp);
    }
}

void Game::initGame(){
    //initialize number of players
   cout << "‫How many players? " << endl;
    cin >> numOfPlayers;

    while(numOfPlayers<2){
        if(numOfPlayers < 0) exit(0);
        else{
        cout << "The number of players must be at least 2"<<endl; 
        cout << "‫How many players? " << endl;
              cin >> numOfPlayers;
        }
}
//initialize number of cards
   cout << "‪How many cards? " << endl;
    cin >> numOfCards;
   while(numOfCards < 1){
       cout << "The number of cards must be at least 1"<<endl; 
       cout << "‪How many cards " << endl;
       cin >> numOfCards;
   }

   //initialize players
   for(size_t i = 0; i < numOfPlayers; i++){
       Player p(i, numOfCards);
       players.push_back(p);
   }
}


void Game::start(){
    initGame();
    int i = 0;
    while(!isWin){
        cout << "current: " << currentCard <<endl;
        Player *p = &players.at(i%players.size());
        if(p->play(currentCard))
            currentCard = p->myLastTurn;
            turn(currentCard, i);
        if(p->getnumOfCards()==0){//check if player won
            isWin=true;
            cout<<"\n"<<p->getName()<<" wins!"<<endl;
         }     
        else cout<<endl;
    }
}

void Game::turn(Card& p, int& i){
    
        //stop card
        if(p.get_sign() == sign::STOP){
            rounds += 2;
             if(state =="PLUS1"){
                     i=i+2;                       
                 }else{
                     i=i-2;                     
                 }       
             }
        //plus card
        else if(p.get_sign() == sign::PLUS){
            return;
        }
        //cd card
        else if(p.get_sign() == sign::CD){
             if(state =="PLUS1"){
                     i--;   
                     state ="MINUS1";
                 }else{
                    i++;
                     state = "MINUS1";
                 }
                 rounds++;
        }

        else{
            rounds++;
             if(state =="PLUS1"){
                     i++;                       
                 }else{
                     i--;                     
                 }
            }
}

