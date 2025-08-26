#include "specialclass.h"
#include <QMessageBox>

SpecialClass::SpecialClass() {}

// Poder clase Especial S Dominio de Destruccion
bool SpecialClass::getPowerEX(GameRules &gameRules, NodeBoard *board)
{
    Players *pl = nullptr;
    QString affectedPlayers;
    if (!board)
    {
        return false;
    }

    BoxGraphics *boxCentral = board->getInfo()->getSquare();

    if (boxCentral)
    {
        boxCentral->resetBox(false);
    }

    pl = board->getInfo()->getPlayer();
    if (pl)
    {
        pl->addTotalBox(-1);
        affectedPlayers += "• " + QString(pl->getLetter()) + "\n";
    }

    NodeBoard *boarLeft = board->getLeft();
    if (boarLeft)
    {
        BoxGraphics *boxLeft = boarLeft->getInfo()->getSquare();

        if (boxLeft)
        {
            boxLeft->resetBox(false);
        }
        pl = boarLeft->getInfo()->getPlayer();
        if (pl)
        {
            pl->addTotalBox(-1);
            affectedPlayers += "• " + QString(pl->getLetter()) + "\n";
        }
    }

    NodeBoard *boardUp = board->getUp();
    if (boardUp)
    {
        BoxGraphics *boxUp = boardUp->getInfo()->getSquare();
        if (boxUp)
        {
            boxUp->resetBox(false);
        }
        pl = boardUp->getInfo()->getPlayer();
        if (pl)
        {
            pl->addTotalBox(-1);
            affectedPlayers += "• " + QString(pl->getLetter()) + "\n";
        }
        NodeBoard *boardUpLeft = boardUp->getLeft();
        if (boardUpLeft)
        {
            BoxGraphics *boxdUpLeft = boardUpLeft->getInfo()->getSquare();

            if (boxdUpLeft)
            {
                boxdUpLeft->resetBox(false);
            }
        }
        pl = boardUpLeft->getInfo()->getPlayer();
        if (pl)
        {
            pl->addTotalBox(-1);
            affectedPlayers += "• " + QString(pl->getLetter()) + "\n";
        }
    }

    if (!affectedPlayers.isEmpty())
    {
        QMessageBox::information(
            nullptr,
            "Jugadores Afectados",
            "Poder Especial Activado!\n\nJugadores afectados:\n" + affectedPlayers
            );
    }
    else
    {
        QMessageBox::information(
            nullptr, "Poder Especial",
            "Poder Especial Activado!\n\nNo se afectó a ningun jugador"
            );
    }
    return true;
}
