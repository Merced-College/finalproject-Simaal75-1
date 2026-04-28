//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <string>

class Deck {
private:
    std::vector<Card> cards;

public:
    bool loadFromCSV(const std::string& filename);
    void shuffleDeck();
    Card dealCard();
    int size() const;
    bool empty() const;
    void clear();
};

#endif