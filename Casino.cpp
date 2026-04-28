//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Casino.h"
#include <iostream>
#include <limits>

void Casino::showMenu() const {
    std::cout << "\n==============================\n";
    std::cout << "CASINO NIGHTS\n";
    std::cout << "==============================\n";
    std::cout << "Player: " << player.getName() << "\n";
    std::cout << "Balance: $" << player.getBalance() << "\n";
    std::cout << "1. Play Blackjack\n";
    std::cout << "2. Play High Card\n";
    std::cout << "3. Show Scoreboard\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose: ";
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

    if (name.empty()) {
        name = "Player";
    }

    player.setName(name);
    player.setBalance(100);
}

void Casino::run() {
    if (!deck.loadFromCSV("cards.csv")) {
        std::cout << "Could not load cards.csv\n";
        return;
    }

    deck.shuffleDeck();
    setupPlayer();

    bool running = true;

    while (running) {
        if (player.getBalance() <= 0) {
            std::cout << "\nYou are out of money.\n";
            break;
        }

        showMenu();
        int choice = getChoice();

        if (choice == 1) {
            blackjackGame.play(player, deck, scores);
        } else if (choice == 2) {
            highCardGame.play(player, deck, scores);
        } else if (choice == 3) {
            scores.printSummary(player.getName(), player.getBalance());
        } else if (choice == 4) {
            running = false;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    scores.printSummary(player.getName(), player.getBalance());
    scores.saveToCSV("session_stats.csv", player.getName(), player.getBalance());
    std::cout << "Session saved to session_stats.csv\n";
}