#ifndef NODEBOARD_H
#define NODEBOARD_H
#include "node.h"
#include "nodoinfo.h"

class NodeBoard : public Node
{
private:
    NodeBoard *up;
    NodeBoard *down;
    NodeBoard *left;
    NodeBoard *right;
    NodoInfo *info;

public:
    // constructor
    NodeBoard(int x, int y);

    // destructor
    virtual ~NodeBoard();

    // metodos de construcion del tablero
    static NodeBoard*** createBoard(int rows, int columns);
    static void connectNode(NodeBoard*** board, int rows, int columns);
    static void deleteBoard(NodeBoard*** board, int rows, int columns);

    // metodos
    bool isConnectedRightAndDown();
    bool isConnectedLeftAndUp();

    // getter y setter
    NodeBoard *getUp() const;
    NodeBoard *getDown() const;
    NodeBoard *getLeft() const;
    NodeBoard *getRight() const;
    NodoInfo *getInfo() const;

    void setUp(NodeBoard *node);
    void setDown(NodeBoard *node);
    void setLeft(NodeBoard *node);
    void setRight(NodeBoard *node);
    void setInfo(NodoInfo *infO);
};

#endif // NODEBOARD_H
