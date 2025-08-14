#ifndef NODELINKED_H
#define NODELINKED_H
#include "node.h"
#include "nodeboard.h"

class NodeLinked
{
private:
    Node *startLinked;
    Node *endLinked;
    bool power;

public:
    NodeLinked();

    ~NodeLinked() = default;

    void setLinked(Node *startLinked, Node *endLinked, bool power);

    Node *getStartLinked() const;
    Node *getEndLinked() const;
    bool getPower() const;

    void setStartLinked(Node *startLinked);
    void seEndLinked(Node *endLinked);
    bool setPower(bool power);
};

#endif // NODELINKED_H
