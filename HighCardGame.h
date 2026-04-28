//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef HIGHCARDGAME_H
#define HIGHCARDGAME_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"

class HighCardGame {
private:
    int getValidBet(int balance) const;

public:
    void play(Player& player, Deck& deck, ScoreManager& scores);
};

#endif