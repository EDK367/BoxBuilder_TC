#include "firstclass.h"

FirstClass::FirstClass() {}

// poder maldito Clase A Bloqueo
bool FirstClass::getPowerBL(GameRules &gameRules, NodeBoard *board, Players *playerCurrent)
{
    if (!board)
    {
        return false;
    }

    NodeInfo *info = board->getInfo();

    // validacion arriba y de izqueirda en la n + 1
    NodeBoard *boardDown = board->getDown();
    if (boardDown)
    {
        NodeBoard *boardLower = boardDown->getRight();
        if (boardLower)
        {
            NodeInfo *infoUL = boardLower->getInfo();

            if (infoUL)
            {
                // validacion arriba
                NodeLinked *linkUp = infoUL->getLinkUp();
                if (linkUp && linkUp->getPower() == PowerManager::PowerEnum::BL)
                {
                    Players *playerLink = linkUp->getPlayerLink();
                    if (playerLink && playerLink == playerCurrent)
                    {
                        linkUp->setPower(this->newPower);
                        return false;
                    } else {
                        return true;
                    }
                }

                // validacion izquierda
                NodeLinked *linkLeft = infoUL->getLinkLeft();
                if (linkLeft && linkLeft->getPower() == PowerManager::PowerEnum::BL)
                {
                    Players *playerLink = linkLeft->getPlayerLink();
                    if (playerLink && playerLink == playerCurrent)
                    {
                        linkLeft->setPower(this->newPower);
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    }

    // validacion abajo en n
    NodeLinked *linkDown = info->getLinkDown();
    if (linkDown && linkDown->getPower() == PowerManager::PowerEnum::BL)
    {
        Players *playerLink = linkDown->getPlayerLink();
        if (playerLink && playerLink == playerCurrent)
        {
            linkDown->setPower(this->newPower);
            return false;
        } else {
            return true;
        }
    }

    // validar a la derecha con n
    NodeLinked *linkRight = info->getLinkRight();
    if (linkRight && linkRight->getPower() == PowerManager::PowerEnum::BL)
    {
        Players *playerLink = linkRight->getPlayerLink();
        if (playerLink && playerLink == playerCurrent)
        {
            linkRight->setPower(this->newPower);
            return false;
        } else {
            return true;
        }
    }

    return false;
}

// poder maldito Clase A Escurridizo
bool FirstClass::getPowerES(PowerManager::PowerEnum power)
{
    if (power == PowerManager::PowerEnum::ES)
    {
        return true;
    }
    return false;
}

// reset de poder maldio Clase A bloqueo
void FirstClass::resetPowerBL(GameRules &gameRules)
{
    for (int i = 0; i < gameRules.getSizeVector(); i++)
    {
        ControllerBL *controller = gameRules.getVectorElement(i);
        if (controller)
        {

            if (controller->getCount() > 0 && (gameRules.getFront()->getPlayer() != controller->getNodeLinkedController()->getPlayerLink()))
            {
                controller->setCount(-1);
            }
            if (controller->getCount() < 1) {
                controller->getNodeLinkedController()->setPower(PowerManager::PowerEnum::NONE);
                gameRules.popVector(i);
                i--;
            }
        }
    }

}
