//
// Created by ondrej on 26.12.21.
//

#include "Player.h"

Player::Player(const int posX, const int posY) : posX(posX), posY(posY) {}

Player::~Player() {}

int Player::getPosX() {
    return posX;
}

int Player::getPosY() {
    return posY;
}

void Player::changePosX(int value) {
    posX += value;
}

void Player::changePosY(int value) {
    posY += value;
}

char Player::getSkin() const {
    return skin;
}

void Player::setSkin(int skinNumber) {
    char skin = availableSkins[skinNumber];
    Player::skin = skin;
}

Player::eDirection Player::getDir() const {
    return dir;
}

void Player::setDir(Player::eDirection dir) {
    Player::dir = dir;
}
