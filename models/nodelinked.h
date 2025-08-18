#ifndef NODELINKED_H
#define NODELINKED_H
#include "node.h"
#include "nodeboard.h"
#include "enum/powermanager.h"

class NodeLinked
{
private:
    Node *startLinked;
    Node *endLinked;
    PowerManager::PowerEnum power;

public:
    NodeLinked();

    ~NodeLinked() = default;

    void setLinked(Node *startLinked, Node *endLinked, PowerManager::PowerEnum power);

    Node *getStartLinked() const;
    Node *getEndLinked() const;
    PowerManager::PowerEnum getPower() const;

    void setStartLinked(Node *startLinked);
    void seEndLinked(Node *endLinked);
    void setPower(PowerManager::PowerEnum power);
};

#endif // NODELINKED_H
