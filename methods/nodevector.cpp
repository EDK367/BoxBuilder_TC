#include "nodevector.h"

NodeVector::NodeVector() : nodeLinked(nullptr), size(0)
{}

NodeVector::~NodeVector() {
    for (int i = 0; i < size; ++i) {
        delete nodeLinked[i];
    }
    delete[] nodeLinked;
}

void NodeVector::push(NodeLinked *newNodeLinked)
{
    resize();

    NodeLinked **newArray = new NodeLinked*[size];
    for (int i = 0; i < size; ++i)
    {
        if (nodeLinked) {
            newArray[i] = nodeLinked[i];
        }
    }
    newArray[size - 1] = newNodeLinked;

    delete[] nodeLinked;
    nodeLinked = newArray;
}

void NodeVector::resize()
{
    size++;
}

NodeLinked *NodeVector::getNode(int index) const
{
    if (index < 0)
    {
        return nullptr;
    }
    return nodeLinked[index];
}

int NodeVector::getSize() const
{
    return size;
}
