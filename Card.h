//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef CARD_H
#define CARD_H

#include <string>

/*
Class: Card

Description:
Represents one playing card.
Stores the card suit, rank, and value.
This keeps card information organized instead of using separate variables everywhere.

Data Structure Requirement:
DATA STRUCTURE #4 - string
Strings store the suit and rank of each card.
*/

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