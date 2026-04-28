//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"

class BlackjackGame {
private:
    int getHandValue(const std::vector<Card>& hand) const;
    void showHand(const std::vector<Card>& hand, bool hideFirstCard) const;
    int getValidBet(int balance) const;

public:
    void play(Player& player, Deck& deck, ScoreManager& scores);
};

#endif