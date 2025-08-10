#include "nodeboard.h"
#include <stdexcept>

NodeBoard::NodeBoard(int x, int y) : Node(x, y),
    up(nullptr),  down(nullptr),
    left(nullptr), right(nullptr)
{}

NodeBoard ***NodeBoard::createBoard(int rows, int columns)
{
    if (rows < 3 || columns < 3)
    {
        throw std::invalid_argument("El tablero no puede ser de ese tamaño");
    }

    NodeBoard ***board = new NodeBoard**[rows];
    for (int i = 0; i < rows; ++i)
    {
        board[i] = new NodeBoard*[columns];
        for (int j = 0; j < columns; ++j)
        {
            board[i][j] = new NodeBoard(i, j);
        }
    }
    connectNode(board, rows, columns);
    return board;
}

void NodeBoard::connectNode(NodeBoard ***board, int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            board[i][j]->setUp(i > 0 ? board[i - 1][j] : nullptr);
            board[i][j]->setDown(i < rows - 1 ? board[i + 1][j] : nullptr);
            board[i][j]->setLeft(j > 0 ? board[i][j - 1] : nullptr);
            board[i][j]->setRight(j < columns - 1 ? board[i][j + 1] : nullptr);
        }
    }
}

// destructor, aca se ve bien lo de los punteros triples
void NodeBoard::deleteBoard(NodeBoard ***board, int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

// getter y setter
NodeBoard *NodeBoard::getUp() const
{
    return up;
}

NodeBoard *NodeBoard::getDown() const
{
    return down;
}

NodeBoard *NodeBoard::getLeft() const
{
    return left;
}

NodeBoard *NodeBoard::getRight() const
{
    return right;
}

void NodeBoard::setUp(NodeBoard *node)
{
    up = node;
}


void NodeBoard::setDown(NodeBoard *node)
{
    down = node;
}


void NodeBoard::setLeft(NodeBoard *node)
{
    left = node;
}


void NodeBoard::setRight(NodeBoard *node)
{
    right = node;
}
