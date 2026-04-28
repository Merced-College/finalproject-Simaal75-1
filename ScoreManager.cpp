//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "ScoreManager.h"
#include <iostream>
#include <fstream>

ScoreManager::ScoreManager() {
    stats["wins"] = 0;
    stats["losses"] = 0;
    stats["ties"] = 0;
    stats["blackjackRounds"] = 0;
    stats["highCardRounds"] = 0;
}

void ScoreManager::addWin() {
    stats["wins"]++;
}

void ScoreManager::addLoss() {
    stats["losses"]++;
}

void ScoreManager::addTie() {
    stats["ties"]++;
}

void ScoreManager::addBlackjackRound() {
    stats["blackjackRounds"]++;
}

void ScoreManager::addHighCardRound() {
    stats["highCardRounds"]++;
}

int ScoreManager::getWins() const {
    return stats.at("wins");
}

int ScoreManager::getLosses() const {
    return stats.at("losses");
}

int ScoreManager::getTies() const {
    return stats.at("ties");
}

int ScoreManager::getBlackjackRounds() const {
    return stats.at("blackjackRounds");
}

int ScoreManager::getHighCardRounds() const {
    return stats.at("highCardRounds");
}

int ScoreManager::getTotalRounds() const {
    return getWins() + getLosses() + getTies();
}

void ScoreManager::printSummary(const std::string& playerName, int balance) const {
    std::cout << "\n==============================\n";
    std::cout << "FINAL SCOREBOARD\n";
    std::cout << "==============================\n";
    std::cout << "Player: " << playerName << "\n";
    std::cout << "Blackjack rounds: " << getBlackjackRounds() << "\n";
    std::cout << "High Card rounds: " << getHighCardRounds() << "\n";
    std::cout << "Total rounds: " << getTotalRounds() << "\n";
    std::cout << "Wins: " << getWins() << "\n";
    std::cout << "Losses: " << getLosses() << "\n";
    std::cout << "Ties: " << getTies() << "\n";
    std::cout << "Ending balance: $" << balance << "\n";
    std::cout << "==============================\n";
}