//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef CASINO_H
#define CASINO_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"
#include "BlackjackGame.h"
#include "HighCardGame.h"

class Casino {
private:
    Player player;
    Deck deck;
    ScoreManager scores;
    BlackjackGame blackjackGame;
    HighCardGame highCardGame;

    void showMenu() const;
    int getChoice() const;
    void setupPlayer();

public:
    void run();
};

#endif