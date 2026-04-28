//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef CASINO_H
#define CASINO_H

#include "Player.h"
#include "Deck.h"
#include "ScoreManager.h"
#include "BlackjackGame.h"
#include "HighCardGame.h"

/*
Class: Casino

Description:
Controls the main casino menu and connects all parts of the program.
This class keeps main.cpp small and makes the project more organized.
*/

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