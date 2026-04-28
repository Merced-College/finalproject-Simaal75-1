//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "BlackjackGame.h"
#include <iostream>
#include <limits>

/*
Algorithm #2 - Hand Value (Blackjack)
Calculates total value and handles aces (11 → 1 if needed)
Time Complexity: O(n)
*/
int BlackjackGame::getHandValue(const std::vector<Card>& hand) const {
    int total = 0;
    int aces = 0;

    for (const Card& card : hand) {
        total += card.getValue();

        if (card.getValue() == 11) {
            aces++; // count aces separately
        }
    }

    // convert aces if total too high
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
            std::cout << "Invalid input.\n";
        } 
        else if (bet <= 0 || bet > balance) {
            std::cout << "Invalid bet amount.\n";
        } 
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return bet;
        }
    }
}

void BlackjackGame::play(Player& player, Deck& deck, ScoreManager& scores) {

    // reload deck if too small
    if (deck.size() < 15) {
        deck.loadFromCSV("cards.csv");
        deck.shuffleDeck();
    }

    scores.addBlackjackRound();

    player.clearHand();
    Player dealer("Dealer", 0);

    std::cout << "\n===== BLACKJACK =====\n";

    int bet = getValidBet(player.getBalance());

    // deal starting cards
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    bool playerTurn = true;

    // player decision loop
    while (playerTurn) {
        std::cout << "\nYour hand:\n";
        showHand(player.getHand(), false);

        int total = getHandValue(player.getHand());
        std::cout << "Total: " << total << "\n";

        std::cout << "\nDealer shows:\n";
        showHand(dealer.getHand(), true);

        if (total >= 21) break;

        std::string choice;
        std::cout << "\nHit or stand? ";
        std::getline(std::cin, choice);

        if (choice == "hit" || choice == "h") {
            player.addCard(deck.dealCard());
        } else {
            playerTurn = false;
        }
    }

    // dealer logic
    while (getHandValue(dealer.getHand()) < 17) {
        dealer.addCard(deck.dealCard());
    }

    int p = getHandValue(player.getHand());
    int d = getHandValue(dealer.getHand());

    /*
    Algorithm #3 - Winner Logic
    Compares totals
    */
    if (p > 21) {
        std::cout << "You busted.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } 
    else if (d > 21 || p > d) {
        std::cout << "You win.\n";
        player.addBalance(bet);
        scores.addWin();
    } 
    else if (d > p) {
        std::cout << "Dealer wins.\n";
        player.subtractBalance(bet);
        scores.addLoss();
    } 
    else {
        std::cout << "Tie.\n";
        scores.addTie();
    }
}