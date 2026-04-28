//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Card.h"

Card::Card() {
    suit = "";
    rank = "";
    value = 0;
}

Card::Card(std::string suit, std::string rank, int value) {
    this->suit = suit;
    this->rank = rank;
    this->value = value;
}

std::string Card::getSuit() const {
    return suit;
}

std::string Card::getRank() const {
    return rank;
}

int Card::getValue() const {
    return value;
}

std::string Card::toString() const {
    return rank + " of " + suit + " (" + std::to_string(value) + ")";
}