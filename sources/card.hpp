#pragma once
#include <iostream>
using namespace std;
const int MAX_VALUE = 13;
class Card
{
private:
    
    int value;
    string suit;
public:
    Card(int value, string suit): suit(std::move(suit))
    {
        if (value < 1 || value > MAX_VALUE)
        {
            throw invalid_argument("Invalid value");
        }
        this->value = value;
    }
    Card()
    {
        this->value = 1;
        this->suit = "spades";
    }
    // int getValue()
    // {
    //     return this->value;
    // }
    string getSuit()
    {
        return this->suit;
    }
};


