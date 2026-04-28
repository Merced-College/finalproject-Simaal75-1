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
        } 
        else if (bet <= 0 || bet > balance) {
            std::cout << "Bet must be between 1 and " << balance << ".\n";
        } 
        else {
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
    std::cout << "Dealer has a hidden card.\n";

    std::string choice;
    std::cout << "\nCall or fold? ";
    std::getline(std::cin, choice);

    if (choice == "fold" || choice == "Fold" || choice == "f" || choice == "F") {
        int lost = bet / 2;

        if (lost < 1) {
            lost = 1;
        }

        player.subtractBalance(lost);
        scores.addLoss();

        std::cout << "\nYou folded.\n";
        std::cout << "You lost half your bet: $" << lost << "\n";
        std::cout << "Dealer card was: " << dealerCard.toString() << "\n";
        std::cout << "New balance: $" << player.getBalance() << "\n";
        return;
    }

    std::cout << "\nDealer reveals: " << dealerCard.toString() << "\n";

    if (playerCard.getValue() > dealerCard.getValue()) {
        std::cout << "You win High Card.\n";
        player.addBalance(bet);
        scores.addWin();
    } 
    else if (dealerCard.getValue() > playerCard.getValue()) {
        std::cout << "Dealer wins High Card.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } 
    else {
        std::cout << "Tie. No money lost.\n";
        scores.addTie();
    }

    std::cout << "New balance: $" << player.getBalance() << "\n";
}