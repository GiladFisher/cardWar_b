#pragma once
#include <iostream>
using namespace std;
class Card
{
private:
    
    int value;
    string suit;
public:
    Card(int value, string suit)
    {
        if (value < 1 || value > 13)
        {
            throw invalid_argument("Invalid value");
        }
        this->value = value;
        this->suit = suit;
    }
    Card()
    {
        this->value = 1;
        this->suit = "spades";
    }
    int getValue()
    {
        return this->value;
    }
    string getSuit()
    {
        return this->suit;
    }
};


