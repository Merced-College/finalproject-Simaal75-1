//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Deck.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

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
        std::string suit, rank, valueStr;

        getline(ss, suit, ',');
        getline(ss, rank, ',');
        getline(ss, valueStr, ',');

        int value = std::stoi(valueStr);
        cards.push_back(Card(suit, rank, value));
    }

    return true;
}

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

bool Deck::empty() const {
    return cards.empty();
}

void Deck::clear() {
    cards.clear();
}