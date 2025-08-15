#ifndef NODEVECTOR_H
#define NODEVECTOR_H
#include "../models/nodelinked.h"

class NodeVector
{
private:
    NodeLinked **nodeLinked;
    int size;
    void resize();

public:
    NodeVector();
    void push(NodeLinked *newNodeLinked);
    NodeLinked *getNode(int index) const;
    int getSize() const;
    // destructor
    ~NodeVector();
};

#endif // NODEVECTOR_H
