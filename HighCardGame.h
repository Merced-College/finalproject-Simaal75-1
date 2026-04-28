//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef HIGHCARDGAME_H
#define HIGHCARDGAME_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"

/*
Class: HighCardGame

Description:
Runs the High Card game.
The player sees their card and chooses to call or fold.
This gives the second game actual user interaction without being too similar to Blackjack.
*/

class HighCardGame {
private:
    int getValidBet(int balance) const;

public:
    void play(Player& player, Deck& deck, ScoreManager& scores);
};

#endif