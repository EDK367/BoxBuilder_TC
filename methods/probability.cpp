#include "probability.h"


Probability::Probability() {}

bool Probability::powerChance()
{
    random.setLimit(4);

    unsigned int result = random();

    if (result == 1 || result == 2)
    {
        return true;
    }
    return false;
}
