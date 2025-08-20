#include "nodelinked.h"

NodeLinked::NodeLinked() : power(PowerManager::PowerEnum::NONE)
{}


void NodeLinked::setLinked(Node *startLinked, Node *endLinked, PowerManager::PowerEnum power, Players *playerLink)
{
    this->startLinked = startLinked;
    this->endLinked = endLinked;
    this->power = power;
    this->playerLink = playerLink;
}

// getter y setter
Node* NodeLinked::getStartLinked() const
{
    return startLinked;
}

Node* NodeLinked::getEndLinked() const
{
    return endLinked;
}

PowerManager::PowerEnum NodeLinked::getPower() const
{
    return power;
}

Players* NodeLinked::getPlayerLink() const
{
    return playerLink;
}

void NodeLinked::setStartLinked(Node *startLinked)
{
    this->startLinked = startLinked;
}

void NodeLinked::setEndLinked(Node *endLinked)
{
    this->endLinked = endLinked;
}

void NodeLinked::setPower(PowerManager::PowerEnum power)
{
    this->power = power;
}

void NodeLinked::setPlayerLink(Players *playerLink)
{
    this->playerLink = playerLink;
}
