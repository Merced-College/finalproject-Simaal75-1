//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>

/*
Class: Player

Description:
Stores the player's name, balance, and current hand.
This class keeps player information separate from the game logic.

Data Structure Requirement:
DATA STRUCTURE #2 - vector
The player's hand is stored in a vector because cards can be added during the round.
*/
class Player {
private:
    std::string name;
    int balance;
    std::vector<Card> hand;

public:
    Player();
    Player(std::string name, int balance);

    void setName(const std::string& name);
    std::string getName() const;

    void setBalance(int balance);
    int getBalance() const;
    void addBalance(int amount);
    void subtractBalance(int amount);

    void clearHand();
    void addCard(const Card& card);
    const std::vector<Card>& getHand() const;
};

#endif