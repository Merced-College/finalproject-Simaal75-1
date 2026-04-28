//Simaal B
//CPSC 25 - Final Project
//Fall 2025

#include "BlackjackGame.h"
#include <iostream>
#include <limits>

/*
Algorithm Requirement:
ALGORITHM #2 - Blackjack Hand Value

Description:
Calculates the total value of a Blackjack hand.
Aces start as 11, but change to 1 if the player would bust.

Time Complexity:
O(n), because it checks each card in the hand.
*/

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

/*
Algorithm Requirement:
ALGORITHM #3 - Bet Validation

Description:
Makes sure the player enters a valid bet.
The bet must be a number, greater than 0, and not more than the player's balance.

Time Complexity:
O(1) for each check, but it repeats until valid input is entered.
*/

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

    /*
    Algorithm Requirement:
    ALGORITHM #4 - Blackjack Winner Logic

    Description:
    Compares player and dealer totals to decide who wins.
    It also updates balance and score stats.

    Time Complexity:
    O(1), because it only uses direct comparisons.
    */
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