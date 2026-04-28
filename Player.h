//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>

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