//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string suit;
    std::string rank;
    int value;

public:
    Card();
    Card(std::string suit, std::string rank, int value);

    std::string getSuit() const;
    std::string getRank() const;
    int getValue() const;

    std::string toString() const;
};

#endif