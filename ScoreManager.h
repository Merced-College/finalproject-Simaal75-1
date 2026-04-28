//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <map>
#include <string>

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
    void saveToCSV(const std::string& filename, const std::string& playerName, int balance) const;
};

#endif