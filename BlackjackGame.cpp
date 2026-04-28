//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "BlackjackGame.h"
#include <iostream>
#include <limits>

int BlackjackGame::getHandValue(const std::vector<Card>& hand) const {
    int total = 0;
    int aces = 0;

    for (const Card& card : hand) {
        total += card.getValue();
        if (card.getValue() == 11) {
            aces++;
        }
    }

    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}

void BlackjackGame::showHand(const std::vector<Card>& hand, bool hideFirstCard) const {
    for (int i = 0; i < (int)hand.size(); i++) {
        if (hideFirstCard && i == 0) {
            std::cout << "- [Hidden Card]\n";
        } else {
            std::cout << "- " << hand[i].toString() << "\n";
        }
    }
}

int BlackjackGame::getValidBet(int balance) const {
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

void BlackjackGame::play(Player& player, Deck& deck, ScoreManager& scores) {
    if (deck.size() < 15) {
        deck.loadFromCSV("cards.csv");
        deck.shuffleDeck();
    }

    scores.addBlackjackRound();

    player.clearHand();
    Player dealer("Dealer", 0);
    dealer.clearHand();

    std::cout << "\n===== BLACKJACK =====\n";
    std::cout << "Balance: $" << player.getBalance() << "\n";

    int bet = getValidBet(player.getBalance());

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    bool playerTurn = true;

    while (playerTurn) {
        std::cout << "\nYour hand:\n";
        showHand(player.getHand(), false);
        std::cout << "Your total: " << getHandValue(player.getHand()) << "\n";

        std::cout << "\nDealer hand:\n";
        showHand(dealer.getHand(), true);

        int total = getHandValue(player.getHand());

        if (total == 21) {
            std::cout << "You have 21.\n";
            break;
        }

        if (total > 21) {
            std::cout << "You busted.\n";
            player.subtractBalance(bet);
            scores.addLoss();
            return;
        }

        std::string choice;
        std::cout << "\nHit or stand? ";
        std::getline(std::cin, choice);

        if (choice == "hit" || choice == "Hit" || choice == "h" || choice == "H") {
            player.addCard(deck.dealCard());
        } else {
            playerTurn = false;
        }
    }

    while (getHandValue(dealer.getHand()) < 17) {
        dealer.addCard(deck.dealCard());
    }

    int playerTotal = getHandValue(player.getHand());
    int dealerTotal = getHandValue(dealer.getHand());

    std::cout << "\nFinal hands:\n";
    std::cout << "\nYour hand:\n";
    showHand(player.getHand(), false);
    std::cout << "Your total: " << playerTotal << "\n";

    std::cout << "\nDealer hand:\n";
    showHand(dealer.getHand(), false);
    std::cout << "Dealer total: " << dealerTotal << "\n";

    if (dealerTotal > 21) {
        std::cout << "\nDealer busted. You win.\n";
        player.addBalance(bet);
        scores.addWin();
    } else if (playerTotal > dealerTotal) {
        std::cout << "\nYou win.\n";
        player.addBalance(bet);
        scores.addWin();
    } else if (dealerTotal > playerTotal) {
        std::cout << "\nDealer wins.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } else {
        std::cout << "\nTie.\n";
        scores.addTie();
    }
}