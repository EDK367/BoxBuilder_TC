#include "rulesgame.h"

RulesGame::RulesGame(int size)
    : max(size), count(0) {
    players = new Players[max];
}

RulesGame::~RulesGame() {
    delete[] players;
}

void RulesGame::addPlayer(const Players& player) {
    if (count < max) {
        players[count++] = player;
    }
}

void RulesGame::deletePlayers() {
    count = 0;
}

Players RulesGame::getPlayer(int index) const {
    if (index >= 0 && index < count) {
        return players[index];
    }
    return Players();
}
