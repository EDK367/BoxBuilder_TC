#include <cmath>

void minBoard(int players, int& row, int& column) {
    int minB;

    minB = players * 3;
    int size = 1;

    while (size * size < minB) {
        ++size;
    }

    row = size;
    column = size;
}

bool validationBoard(int size, int minSize) {
    if (size < minSize) {
        return false;
    }
    return true;
}
