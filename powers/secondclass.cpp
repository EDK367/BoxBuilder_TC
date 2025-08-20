#include "secondclass.h"

SecondClass::SecondClass() {}

bool SecondClass::getPowerTS(GameRules &gameRules, NodeBoard *board, Players *playerCurrent)
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
                if (linkUp && linkUp->getPower() == PowerManager::PowerEnum::TS)
                {
                    Players *playerLink = linkUp->getPlayerLink();
                    if (playerLink && playerLink != playerCurrent)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        playerLink->addPoints(1);
                        return true;
                    }
                }

                NodeLinked *linkLeft = infoUL->getLinkLeft();
                if (linkLeft && linkLeft->getPower() == PowerManager::PowerEnum::TS)
                {
                    // validacion izquierda
                    Players *playerLink = linkLeft->getPlayerLink();
                    if (playerLink && playerLink != playerCurrent)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        playerLink->addPoints(1);
                        return true;
                    }
                }
            }
        }
    }

    // validacion abajo en n
    NodeLinked *linkDown = info->getLinkDown();
    if (linkDown && linkDown->getPower() == PowerManager::PowerEnum::TS)
    {
        Players *playerLink = linkDown->getPlayerLink();
        if (playerLink && playerLink != playerCurrent)
        {
            BoxGraphics *boxWin = info->getSquare();
            if (boxWin)
            {
                boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
            }
            playerLink->addPoints(1);
            return true;
        }
    }


    // validar a la derecha con n
    NodeLinked *linkRight = info->getLinkRight();
    if (linkRight && linkRight->getPower() == PowerManager::PowerEnum::TS)
    {
        Players *playerLink = linkRight->getPlayerLink();
        if (playerLink && playerLink != playerCurrent)
        {
            BoxGraphics *boxWin = info->getSquare();
            if (boxWin)
            {
                boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
            }
            playerLink->addPoints(1);
            return true;
        }
    }

    return false;
}
