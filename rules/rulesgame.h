#ifndef RULESGAME_H
#define RULESGAME_H
#include "../models/players.h"


class RulesGame
{
private:
    Players* players;
    int max;
    int count;

public:

    RulesGame(int size);
    ~RulesGame();

    void addPlayer(const Players& p);
    void deletePlayers();
    Players getPlayer(int index) const;

};

#endif // RULESGAME_H
