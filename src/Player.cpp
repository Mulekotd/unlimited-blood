#include <iostream>
#include <math.h>

#include "Player.h"
#include "Globals.h"

// Construtor
Player::Player(void)
    : Entity(SCREEN_CENTER_X, SCREEN_CENTER_Y, 50, 50), mana(100) {
}

// Destrutor
Player::~Player() {}

int Player::getMana() const {
    return this->mana;
}

void Player::setMana(int mana) {
    this->mana = mana;
}

std::u32string Player::getName() const {
    return this->name;
};

void Player::setName(const std::u32string& name) {
    this->name = name;
}
