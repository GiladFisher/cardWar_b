#include "game.hpp"
#include "card.hpp"
#include <iostream>

using namespace ariel;
void Game::playTurn(){
    if (this->p1.cards.size() == 0 || this->p2.cards.size() == 0){
        throw "No more cards to play.";
    }
    if (this->p1.name == this->p2.name){
        throw "Same player";
    }

    string log = "";
    int c1 = 0 + p1.cards.top();
    // cout << p1.name << " played " << c1 << " of Spades ";
    log += p1.name + " played " + to_string(c1) + " of Spades ";
    int c2 = this->p2.cards.top();
    // cout << this->p2.name << " played " << c2 << " of Spades ";
    log += this->p2.name + " played " + to_string(c2) + " of Spades ";
    this->p1.cards.pop();
    this->p2.cards.pop();
    if (c1 > c2){
        p1.cardsTaken += 2;
        // cout << p1.name << " wins." << endl;
        log += p1.name + " wins.";
        this->lastTurn = log;
        this->log += "\n" + log;
    }
    else if (c1 < c2){
        p2.cardsTaken += 2;
        // cout << p2.name << " wins." << endl;
        log += p2.name + " wins.";
        this->lastTurn = log;
        this->log += "\n" + log;
    }
    else{
            // tie breaker
            // cout << "Draw. ";
            log += "Draw. ";
            int to_add = 2;
            while (c1 == c2){
                if (p1.cards.size() <= 1 || p2.cards.size() <= 1){
                    break;
                }
                p1.cards.pop();
                p2.cards.pop();
                c1 = this->p1.cards.top();
                log += p1.name + " played " + to_string(c1) + " of Spades ";
                c2 = this->p2.cards.top();
                log += this->p2.name + " played " + to_string(c2) + " of Spades ";
                p1.cards.pop();
                p2.cards.pop();
                to_add += 4;
                if (c1 > c2){
                    p1.cardsTaken += to_add;
                    log += p1.name + " wins.";
                    this->lastTurn = log;
                    this->log += "\n" + log;
                }
                else if (c1 < c2){
                    p2.cardsTaken += to_add;
                    log += p2.name + " wins.";
                    this->lastTurn = log;
                    this->log += "\n" + log;
                }
            }

        }   
}

void Game::playAll(){
    while (p1.cards.size() > 0 && p2.cards.size() > 0){
        this->playTurn();
    }
}

void Game::printLog(){
   cout << this->log << endl;
}
void Game::printWiner(){
    if (p1.cardsTaken > p2.cardsTaken){
        cout << "The Winer is: "<< p1.name << "!" << endl;
    }
    else if (p1.cardsTaken < p2.cardsTaken){
        cout << "The Winer is: "<< p2.name << "!" << endl;
    }
    else{
        cout << "Draw." << endl;
    }
   
}
void Game::printStats(){
   cout << p1.name << " took " << p1.cardsTaken << " cards." << " has " << p1.cards.size() << " cards left." << endl;
    cout << p2.name << " took " << p2.cardsTaken << " cards." << " has " << p2.cards.size() << " cards left." << endl;

}
void Game::printLastTurn(){
    cout << this->lastTurn << endl;
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
}

