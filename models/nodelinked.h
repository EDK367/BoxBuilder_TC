#ifndef NODELINKED_H
#define NODELINKED_H
#include "node.h"
#include "nodeboard.h"
#include "enum/powermanager.h"
#include "players.h"

class NodeLinked
{
private:
    Node *startLinked;
    Node *endLinked;
    PowerManager::PowerEnum power;
    Players *playerLink;

public:
    NodeLinked();

    ~NodeLinked() = default;

    void setLinked(Node *startLinked, Node *endLinked, PowerManager::PowerEnum power, Players *playerLink);

    Node *getStartLinked() const;
    Node *getEndLinked() const;
    PowerManager::PowerEnum getPower() const;
    Players* getPlayerLink() const;

    // Setters individuales
    void setStartLinked(Node *startLinked);
    void setEndLinked(Node *endLinked);
    void setPower(PowerManager::PowerEnum power);
    void setPlayerLink(Players *playerLink);
};

#endif // NODELINKED_H
