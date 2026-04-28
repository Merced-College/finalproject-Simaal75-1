//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#include "Deck.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

bool Deck::loadFromCSV(const std::string& filename) {
    cards.clear();

    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string suit;
        std::string rank;
        std::string valueStr;

        getline(ss, suit, ',');
        getline(ss, rank, ',');
        getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);
        cards.push_back(Card(suit, rank, value));
    }

    return true;
}

/*
Algorithm Requirement:
ALGORITHM #1 - Shuffle Deck

Description:
Randomizes the order of the cards before games are played.
This is used so Blackjack and High Card do not deal cards in the same order every time.

Time Complexity:
O(n), because every card may be moved during the shuffle.
*/

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    if (cards.empty()) {
        return Card();
    }

    Card top = cards.back();
    cards.pop_back();
    return top;
}

int Deck::size() const {
    return (int)cards.size();
}