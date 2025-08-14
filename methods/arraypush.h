#ifndef ARRAYPUSH_H
#define ARRAYPUSH_H
#include "../models/nodelinked.h"

class ArrayPush
{

private:
    NodeLinked *nodeLinked;
    int size;

public:
    ArrayPush();
    void push(NodeLinked &nodeLinked) const;
    // metodos
    void addSize();

};

#endif // ARRAYPUSH_H
