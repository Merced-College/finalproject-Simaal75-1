//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "HighCardGame.h"
#include <iostream>
#include <limits>

int HighCardGame::getValidBet(int balance) const {
    int bet;

    while (true) {
        std::cout << "Enter your bet: $";
        std::cin >> bet;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        } else if (bet <= 0 || bet > balance) {
            std::cout << "Bet must be between 1 and " << balance << ".\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return bet;
        }
    }
}

void HighCardGame::play(Player& player, Deck& deck, ScoreManager& scores) {
    if (deck.size() < 5) {
        deck.loadFromCSV("cards.csv");
        deck.shuffleDeck();
    }

    scores.addHighCardRound();

    std::cout << "\n===== HIGH CARD =====\n";
    std::cout << "Balance: $" << player.getBalance() << "\n";

    int bet = getValidBet(player.getBalance());

    Card playerCard = deck.dealCard();
    Card dealerCard = deck.dealCard();

    std::cout << "\nYour card: " << playerCard.toString() << "\n";
    std::cout << "Dealer card: " << dealerCard.toString() << "\n";

    if (playerCard.getValue() > dealerCard.getValue()) {
        std::cout << "You win.\n";
        player.addBalance(bet);
        scores.addWin();
    } else if (dealerCard.getValue() > playerCard.getValue()) {
        std::cout << "Dealer wins.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } else {
        std::cout << "Tie.\n";
        scores.addTie();
    }
}