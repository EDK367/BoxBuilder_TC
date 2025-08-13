#include "arraymess.h"
#include <utility>

ArrayMess::ArrayMess() {}

void ArrayMess::shufflePlayers(Players *playersInput, int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        random.setLimit(i + 1);
        int j = random();
        std::swap(playersInput[i], playersInput[j]);
    }
}
