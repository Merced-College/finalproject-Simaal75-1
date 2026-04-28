//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Casino.h"
#include <iostream>
#include <limits>

void Casino::showMenu() const {
    std::cout << "\n===== CASINO =====\n";
    std::cout << "1. Blackjack\n";
    std::cout << "2. High Card\n";
    std::cout << "3. Scoreboard\n";
    std::cout << "4. Exit\n";
}

int Casino::getChoice() const {
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void Casino::setupPlayer() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (name.empty()) name = "Player";

    player.setName(name);
    player.setBalance(100);
}

void Casino::run() {

    if (!deck.loadFromCSV("cards.csv")) {
        std::cout << "Error loading cards.csv\n";
        return;
    }

    deck.shuffleDeck();

    setupPlayer();

    bool running = true;

    // main loop
    while (running) {
        showMenu();

        int choice = getChoice();

        if (choice == 1) {
            blackjackGame.play(player, deck, scores);
        } 
        else if (choice == 2) {
            highCardGame.play(player, deck, scores);
        } 
        else if (choice == 3) {
            scores.printSummary(player.getName(), player.getBalance());
        } 
        else if (choice == 4) {
            running = false;
        } 
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    scores.printSummary(player.getName(), player.getBalance());
}