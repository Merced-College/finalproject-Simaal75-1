//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <map>
#include <string>

/*
Class: ScoreManager

Description:
Tracks wins, losses, ties, and how many rounds of each game were played.
This keeps the scoreboard separate from Blackjack and High Card.

Data Structure Requirement:
DATA STRUCTURE #3 - map
The map stores stat names as keys and numbers as values.
*/
class ScoreManager {
private:
    std::map<std::string, int> stats;

public:
    ScoreManager();

    void addWin();
    void addLoss();
    void addTie();
    void addBlackjackRound();
    void addHighCardRound();

    int getWins() const;
    int getLosses() const;
    int getTies() const;
    int getBlackjackRounds() const;
    int getHighCardRounds() const;
    int getTotalRounds() const;

    void printSummary(const std::string& playerName, int balance) const;
};

#endif