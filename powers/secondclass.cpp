#include "secondclass.h"

SecondClass::SecondClass() {}

// poder maldito Clase B Trampra Oculta
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
                        linkUp->setPower(this->newPower);
                        playerLink->addPoints(1);
                        resetTurns(gameRules, playerLink);
                        return true;
                    }
                }

                // validacion izquierda
                NodeLinked *linkLeft = infoUL->getLinkLeft();
                if (linkLeft && linkLeft->getPower() == PowerManager::PowerEnum::TS)
                {
                    Players *playerLink = linkLeft->getPlayerLink();
                    if (playerLink && playerLink != playerCurrent)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        linkLeft->setPower(this->newPower);
                        playerLink->addPoints(1);
                        resetTurns(gameRules, playerLink);
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
            linkDown->setPower(this->newPower);
            playerLink->addPoints(1);
            resetTurns(gameRules, playerLink);
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
            linkRight->setPower(this->newPower);
            playerLink->addPoints(1);
            resetTurns(gameRules, playerLink);
            return true;
        }
    }

    return false;
}

// poder maldito Clase B Union Futura
bool SecondClass::getPowerUF(GameRules &gameRules, NodeBoard *board, Players *playerCurrent)
{
    if (!board)
    {
        return false;
    }
    NodeInfo *info = board->getInfo();
    NodeBoard *boardDown = board->getDown();

    if (boardDown)
    {
        // validacion arriba y de izqueirda en la n + 1
        NodeBoard *boardLower = boardDown->getRight();
        if (boardLower)
        {
            NodeInfo *infoUL = boardLower->getInfo();

            if (infoUL)
            {
                // validacion arriba
                NodeLinked *linkUp = infoUL->getLinkUp();
                if (linkUp && linkUp->getPower() == PowerManager::PowerEnum::UF)
                {
                    Players *playerLink = linkUp->getPlayerLink();
                    if (playerLink && playerLink == playerCurrent)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        linkUp->setPower(this->newPower);
                        playerCurrent->addPoints(2);
                        return true;
                    }
                }
                // validacion izquierda
                NodeLinked *linkLeft = infoUL->getLinkLeft();
                if (linkLeft && linkLeft->getPower() == PowerManager::PowerEnum::UF)
                {
                    Players *playerLink = linkLeft->getPlayerLink();
                    if (playerLink && playerLink == playerCurrent)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        linkLeft->setPower(this->newPower);
                        playerCurrent->addPoints(2);
                        return true;
                    }
                }
            }
        }

        NodeLinked *linkDown = info->getLinkDown();
        if (linkDown && linkDown->getPower() == PowerManager::PowerEnum::UF)
        {
            Players *playerLink = linkDown->getPlayerLink();
            if (playerLink && playerLink == playerCurrent)
            {
                BoxGraphics *boxWin = info->getSquare();
                if (boxWin)
                {
                    boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                }
                linkDown->setPower(this->newPower);
                playerCurrent->addPoints(2);
                return true;
            }
        }

        // validar a la derecha con n
        NodeLinked *linkRight = info->getLinkRight();
        if (linkRight && linkRight->getPower() == PowerManager::PowerEnum::UF)
        {
            Players *playerLink = linkRight->getPlayerLink();
            if (playerLink && playerLink == playerCurrent)
            {
                BoxGraphics *boxWin = info->getSquare();
                if (boxWin)
                {
                    boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                }
                linkRight->setPower(this->newPower);
                playerLink->addPoints(2);
                return true;
            }
        }
    }
    return false;
}

// poder maldito Clase B A que Costo
bool SecondClass::getPowerAC(GameRules &gameRules, NodeBoard *board, Players *playerCurrent)
{
    if (!board)
    {
        return false;
    }

    NodeInfo *info = board->getInfo();
    NodeBoard *boardDown = board->getDown();

    if (boardDown)
    {
        // validacion arriba y de izqueirda en la n + 1
        NodeBoard *boardLower = boardDown->getRight();
        if (boardLower)
        {
            NodeInfo *infoUL = boardLower->getInfo();

            if (infoUL)
            {
                // validacion arriba
                NodeLinked *linkUp = infoUL->getLinkUp();
                if (linkUp && linkUp->getPower() == PowerManager::PowerEnum::AC)
                {
                    Players *playerLink = linkUp->getPlayerLink();
                    if (playerLink)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        linkUp->setPower(this->newPower);
                        playerCurrent->addPoints(1);
                        return true;
                    }
                }
                // validacion izquierda
                NodeLinked *linkLeft = infoUL->getLinkLeft();
                if (linkLeft && linkLeft->getPower() == PowerManager::PowerEnum::AC)
                {
                    Players *playerLink = linkLeft->getPlayerLink();
                    if (playerLink)
                    {
                        BoxGraphics *boxWin = info->getSquare();
                        if (boxWin)
                        {
                            boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                        }
                        linkLeft->setPower(this->newPower);
                        playerCurrent->addPoints(1);
                        return true;
                    }
                }
            }
        }

        NodeLinked *linkDown = info->getLinkDown();
        if (linkDown && linkDown->getPower() == PowerManager::PowerEnum::AC)
        {
            Players *playerLink = linkDown->getPlayerLink();
            if (playerLink)
            {
                BoxGraphics *boxWin = info->getSquare();
                if (boxWin)
                {
                    boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                }
                linkDown->setPower(this->newPower);
                playerCurrent->addPoints(1);
                return true;
            }
        }

        // validar a la derecha con n
        NodeLinked *linkRight = info->getLinkRight();
        if (linkRight && linkRight->getPower() == PowerManager::PowerEnum::AC)
        {
            Players *playerLink = linkRight->getPlayerLink();
            if (playerLink)
            {
                BoxGraphics *boxWin = info->getSquare();
                if (boxWin)
                {
                    boxWin->insertPlayer(playerLink->getLetter(), playerLink->getColor());
                }
                linkRight->setPower(this->newPower);
                playerCurrent->addPoints(1);
                return true;
            }
        }
    }
    return false;
}

// poder maldito Clase B Llave maestra
bool SecondClass::getPowerLS(PowerManager::PowerEnum power)
{
    if (power == PowerManager::PowerEnum::LS)
    {
        return true;
    }
    return false;
}

// funcion para resetear turno
void SecondClass::resetTurns(GameRules &gameRules, Players *playerLink)
{
    Players *playerIndex = nullptr;
    do
    {
        gameRules.dequeuePlayer();
        playerIndex = gameRules.getFront()->getPlayer();
    } while(playerIndex != playerLink);
}


















