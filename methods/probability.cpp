#include "probability.h"


Probability::Probability() {}

bool Probability::powerChance()
{
    random.setLimit(3);

    unsigned int result = random();

    if (result == 1)
    {
        return true;
    }
    return false;
}

bool Probability::evasiveChance()
{
    random.setLimit(2);
    unsigned int result = random();
    if (result == 1)
    {
        return true;
    }
    return false;

}
