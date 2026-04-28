//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Deck.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

bool Deck::loadFromCSV(const std::string& filename) {
    cards.clear(); // reset deck before loading

    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // file didn't open
    }

    std::string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        // split csv line into parts
        std::stringstream ss(line);
        std::string suit, rank, valueStr;

        getline(ss, suit, ',');
        getline(ss, rank, ',');
        getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);

        // add card to deck
        cards.push_back(Card(suit, rank, value));
    }

    return true;
}

/*
Algorithm #1 - Shuffle Deck
Randomizes the order of the cards before gameplay.
Time Complexity: O(n)
*/
void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());

    // built-in shuffle on vector
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    if (cards.empty()) return Card();

    // take last card (top of deck)
    Card top = cards.back();

    // remove it so it can't be reused
    cards.pop_back();

    return top;
}

int Deck::size() const {
    return (int)cards.size();
}