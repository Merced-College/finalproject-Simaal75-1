//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Deck.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>

bool Deck::loadFromCSV(const std::string& filename) {
    cards.clear(); // clear old deck before loading new one

    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // file didn't load
    }

    std::string line;

    // read each line from csv file
    while (getline(file, line)) {
        if (line.empty()) continue;

        // split line into suit, rank, value
        std::stringstream ss(line);
        std::string suit, rank, valueStr;

        getline(ss, suit, ',');
        getline(ss, rank, ',');
        getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);

        // create card object and store it
        cards.push_back(Card(suit, rank, value));
    }

    return true;
}

/*
Algorithm 1: Shuffle Deck

Randomizes order of cards so game is not predictable.

Time Complexity: O(n)
*/
void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());

    // shuffle entire vector of cards
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    if (cards.empty()) return Card();

    // take last card (top of deck)
    Card top = cards.back();

    // remove it so it cannot be reused
    cards.pop_back();

    return top;
}

int Deck::size() const {
    return (int)cards.size();
}