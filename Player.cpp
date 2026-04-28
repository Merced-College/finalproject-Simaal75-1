//Simaal B
//CPSC 25 - Final Project
//Spring 2026

#include "Player.h"

Player::Player() {
    name = "";
    balance = 100;
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
    balance += amount;
}

void Player::subtractBalance(int amount) {
    balance -= amount;
}

void Player::clearHand() {
    hand.clear();
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}