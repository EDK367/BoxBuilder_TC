#ifndef CONTROLLERBL_H
#define CONTROLLERBL_H
#include "../../models/nodelinked.h"

class ControllerBL
{
private:
    NodeLinked *nodeLinkedController;
    int count;

public:
    ControllerBL();
    NodeLinked *getNodeLinkedController() const;
    int getCount() const;

    void setNodeLinkedController(NodeLinked *nodeLinked);
    void setCount(int count);
};

#endif // CONTROLLERBL_H
