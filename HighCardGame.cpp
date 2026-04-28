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
        } 
        else if (bet <= 0 || bet > balance) {
            std::cout << "Invalid bet.\n";
        } 
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return bet;
        }
    }
}

void HighCardGame::play(Player& player, Deck& deck, ScoreManager& scores) {

    // reload deck if needed
    if (deck.size() < 5) {
        deck.loadFromCSV("cards.csv");
        deck.shuffleDeck();
    }

    scores.addHighCardRound();

    std::cout << "\n===== HIGH CARD =====\n";

    int bet = getValidBet(player.getBalance());

    // deal one card each
    Card playerCard = deck.dealCard();
    Card dealerCard = deck.dealCard();

    std::cout << "Your card: " << playerCard.toString() << "\n";
    std::cout << "Dealer has a hidden card.\n";

    std::string choice;
    std::cout << "Call or fold? ";
    std::getline(std::cin, choice);

    // folding = safe option (lose half)
    if (choice == "fold" || choice == "f") {
        int loss = bet / 2;
        player.subtractBalance(loss);
        scores.addLoss();

        std::cout << "You folded. Lost $" << loss << "\n";
        return;
    }

    // reveal dealer card
    std::cout << "Dealer card: " << dealerCard.toString() << "\n";

    // compare values
    if (playerCard.getValue() > dealerCard.getValue()) {
        std::cout << "You win.\n";
        player.addBalance(bet);
        scores.addWin();
    } 
    else if (dealerCard.getValue() > playerCard.getValue()) {
        std::cout << "Dealer wins.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } 
    else {
        std::cout << "Tie.\n";
        scores.addTie();
    }

    // update stats after round
}