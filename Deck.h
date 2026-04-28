//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <string>

/*
Class: Deck

Description:
Manages the deck of cards.
It loads cards from cards.csv, shuffles the deck, and deals cards.

Data Structure Requirement:
DATA STRUCTURE #1 - vector
The deck is stored in a vector because it is easy to shuffle and remove cards from.
*/

class Deck {
private:
    std::vector<Card> cards;

public:
    bool loadFromCSV(const std::string& filename);
    void shuffleDeck();
    Card dealCard();
    int size() const;
};

#endif