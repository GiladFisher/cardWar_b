#include <iostream>
#include "player.hpp"
#pragma once
namespace ariel{
class Game{
    
    public:
    Player p1;
    Player p2;
    Game(Player &p1, Player &p2){
        this->p1 = Player(p1.name);
        this->p2 =  Player(p2.name);
        this->shuffle(p1, p2);
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