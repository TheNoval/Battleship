/*

*/
#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif

#include "player.h"
#include <string>
#include <iostream>

Player::Player(std::string name) { // 
    this->board = new Board();
    this->name = name;
}

Player::~Player() {
    delete board;
    board = nullptr;
}

void Player::addHit() {
    hits += 1;
}
void Player::addMiss() {
    misses += 1;
}
int Player::getHits() {
    return hits;
}
int Player::getMisses() {
    return misses;
}

std::string Player::getName() {
    return this->name;
}

void Player::printSelfBoard() {
    board->displayUserBoard();
}

void Player::printOpponentBoard(Player& opponent) {
    opponent.printSelfBoard_forOpponent();
}

void Player::setShips(int size) {
    board->setShips(size);
}

void Player::attacked(int y, int x) {
    board->attackBoard(y, x);
}

void Player::printSelfBoard_forOpponent() {
    board->displayOpponentBoard();
}

bool Player::checkWin() {
    board->checkWin();
}