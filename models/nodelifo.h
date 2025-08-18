#ifndef NODELIFO_H
#define NODELIFO_H
#include "enum/powermanager.h"

class NodeLIFO
{
private:
    PowerManager::PowerEnum power;
    NodeLIFO *next;

public:
    NodeLIFO();
    ~NodeLIFO();

    PowerManager::PowerEnum getPower() const;
    NodeLIFO *getNext() const;

    void setPower(PowerManager::PowerEnum power);
    void setNext(NodeLIFO *next);

};

#endif // NODELIFO_H
