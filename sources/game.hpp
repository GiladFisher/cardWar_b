#include <iostream>
#include "player.hpp"
#pragma once
#include <string>
namespace ariel{
class Game{
    private:
    string lastTurn;
    string log;
    
    public:
    Player &p1;
    Player &p2;
    Game(Player &p1, Player &p2): p1(p1), p2(p2){
        this->shuffle(this->p1, this->p2);
        this->log = "Log: ";
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