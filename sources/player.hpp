#include <iostream>
#pragma once
#include <stack>
using namespace std;
class Player{
    public:
    int cardsTaken;
    int stackSize;
    stack<int> cards;
    Player(string name){
        this->name = name;
        this->cardsTaken = 0;
        this->stackSize = 0;
    }
    Player(){
        this->name = "NoName";
        this->cardsTaken = 0;
        this->stackSize = 0;
    }
    
    string name;
    int cardesTaken();
    int stacksize();
};