#ifndef NODE_H
#define NODE_H

struct NodePosition
{
    int x;
    int y;
};

class Node
{

private:
    // un nodo es un punto
    int x;
    int y;

public:
    // constructor
    Node(int x, int y);

    // destructor
    virtual ~Node() = default;

    // metodos


    // getter and setter
    NodePosition getNodePosition() const;
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
};

#endif // NODE_H
