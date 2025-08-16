#ifndef NODEVECTOR_H
#define NODEVECTOR_H
#include "../models/nodelinked.h"

class NodeVector
{
private:
    NodeLinked **nodeLinked;
    int size;

public:
    NodeVector();

    // destructor
    ~NodeVector();

    void push(NodeLinked *newNodeLinked);
    void pop(int index);
    void sortByStart();

    // getter y setter
    NodeLinked *getNode(int index) const;
    int getSize() const;

};

#endif // NODEVECTOR_H
