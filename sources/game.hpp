#include <iostream>
#include "player.hpp"
#pragma once
namespace ariel{
class Game{
    
    public:
    Player p1;
    Player p2;
    Game(Player p1, Player p2){
        this->p1 = p1;
        this->p2 =  p2;
        this->shuffle(this->p1, this->p2);
        cout << p1.cards.size() << endl;
    }
    void playTurn();
    void playAll();
    void printLog();
    void printWiner();
    void printStats();
    void printLastTurn();
    void shuffle(Player &p1, Player &p2);
};
}