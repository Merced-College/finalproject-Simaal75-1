//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"

/*
Class: BlackjackGame

Description:
Runs the Blackjack game.
It handles betting, dealing, hit/stand choices, dealer rules, and winner checking.
*/

class BlackjackGame {
private:
    int getHandValue(const std::vector<Card>& hand) const;
    void showHand(const std::vector<Card>& hand, bool hideFirstCard) const;
    int getValidBet(int balance) const;

public:
    void play(Player& player, Deck& deck, ScoreManager& scores);
};

#endif