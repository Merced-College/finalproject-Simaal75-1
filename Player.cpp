//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Player.h"

Player::Player() {
    name = "";
    balance = 100; // default starting money
}

Player::Player(std::string name, int balance) {
    this->name = name;
    this->balance = balance;
}

void Player::setName(const std::string& name) {
    this->name = name;
}

std::string Player::getName() const {
    return name;
}

void Player::setBalance(int balance) {
    this->balance = balance;
}

int Player::getBalance() const {
    return balance;
}

void Player::addBalance(int amount) {
    // used when player wins
    balance += amount;
}

void Player::subtractBalance(int amount) {
    // used when player loses
    balance -= amount;
}

void Player::clearHand() {
    // reset hand for new round
    hand.clear();
}

void Player::addCard(const Card& card) {
    // add card to player's hand
    hand.push_back(card);
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}