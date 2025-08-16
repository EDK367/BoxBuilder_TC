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
    size++;
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


void NodeVector::pop(int index)
{
    if (index < 0 || index >= size) return;

    delete nodeLinked[index];

    if (size == 1) {
        delete[] nodeLinked;
        nodeLinked = nullptr;
    } else {
        NodeLinked** newArray = new NodeLinked*[size - 1];
        int j = 0;
        for (int i = 0; i < size; ++i) {
            if (i != index) {
                newArray[j++] = nodeLinked[i];
            }
        }
        delete[] nodeLinked;
        nodeLinked = newArray;
    }
    size--;
}

// ESTE CODIGO SE CAMBIARA YA QUE NO SE SABE COMO FUNCIONA
void NodeVector::sortByStart()
{
    if (size <= 1 || nodeLinked == nullptr) {
        return;
    }

    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if (!nodeLinked[j] || !nodeLinked[j+1] ||
                !nodeLinked[j]->getStartLinked() || !nodeLinked[j+1]->getStartLinked()) {
                continue;
            }

            Node* a = nodeLinked[j]->getStartLinked();
            Node* b = nodeLinked[j+1]->getStartLinked();

            bool shouldSwap = (a->getX() > b->getX()) ||
                              (a->getX() == b->getX() && a->getY() > b->getY());

            if (shouldSwap) {
                NodeLinked* temp = nodeLinked[j];
                nodeLinked[j] = nodeLinked[j+1];
                nodeLinked[j+1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
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
