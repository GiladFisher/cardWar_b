#include "game.hpp"
#include "card.hpp"
#include <iostream>

using namespace ariel;
void Game::playTurn(){
    int c1 = this->p1.cards.top();
    int c2 = this->p2.cards.top();
    this->p1.cards.pop();
    this->p2.cards.pop();
    if (c1 > c2){
        // this->p1.cardesTaken++;
    }
    else if (c1 < c2){
        // this->p2.takeCard();
    }
    else{
        // tie breaker
    }
   
}

void Game::playAll(){
   
}

void Game::printLog(){
   
}
void Game::printWiner(){
   
}
void Game::printStats(){
   
}
void Game::printLastTurn(){
   
}
void Game::shuffle(Player &p1, Player &p2){
   int whole_deck[] = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
                     8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13};
    int cnt = 0;
    int val = 0;
    while (cnt < 52){
        while(val == 0){
            int random = rand() % 52;
            val = whole_deck[random];
            whole_deck[random] = 0;
        }
        if (cnt % 2 == 0){
            p2.cards.push(val);
        }
        else{
            p1.cards.push(val);
        }
        
        cnt++;
        val = 0;
    }
    cout << p1.cards.size() << endl;
    cout << p2.cards.size() << endl;
}

