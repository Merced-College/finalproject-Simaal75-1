//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "HighCardGame.h"
#include <iostream>
#include <limits>

// checks bet input
int HighCardGame::getValidBet(int balance) const {
    int bet;

    while (true) {
        std::cout << "Enter your bet: $";
        std::cin >> bet;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
        } 
        else if (bet <= 0 || bet > balance) {
            std::cout << "Invalid bet amount. You only have $" << balance << ".\n";
        } 
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return bet;
        }
    }
}

void HighCardGame::play(Player& player, Deck& deck, ScoreManager& scores) {

    // reload deck if it gets low
    if (deck.size() < 5) {
        deck.loadFromCSV("cards.csv");
        deck.shuffleDeck();
    }

    scores.addHighCardRound();

    std::cout << "\n===== HIGH CARD =====\n";
    std::cout << "Available balance: $" << player.getBalance() << "\n";

    int bet = getValidBet(player.getBalance());

    // deal one card to player and one hidden card to dealer
    Card playerCard = deck.dealCard();
    Card dealerCard = deck.dealCard();

    std::cout << "\nYour card: " << playerCard.toString() << "\n";
    std::cout << "Dealer has a hidden card.\n";

    std::string choice;
    std::cout << "\nCall or fold? ";
    std::getline(std::cin, choice);

    // fold = safer option, lose half the bet
    if (choice == "fold" || choice == "f") {
        int loss = bet / 2;

        if (loss < 1) {
            loss = 1;
        }

        player.subtractBalance(loss);
        scores.addLoss();

        std::cout << "\nFinal cards:\n";
        std::cout << "Your card: " << playerCard.toString() << "\n";
        std::cout << "Dealer card: " << dealerCard.toString() << "\n";

        std::cout << "\nResult: You folded. You lost $" << loss << ".\n";
        std::cout << "New balance: $" << player.getBalance() << "\n";
        return;
    }

    // call = compare cards and risk full bet
    std::cout << "\nFinal cards:\n";
    std::cout << "Your card: " << playerCard.toString() << "\n";
    std::cout << "Dealer card: " << dealerCard.toString() << "\n";

    std::cout << "\nResult: ";

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