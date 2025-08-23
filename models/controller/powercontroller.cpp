#include "powercontroller.h"

// uso de factory con private y public
// private
PowerController::PowerController(PowerManager::PowerEnum power, Players *playerLink, ClickGraphics *pointerClick)
    : power(power), playerLink(playerLink), pointerClick(pointerClick)
{ }

// public
PowerController *PowerController::createController(PowerManager::PowerEnum power, Players *playerLink, ClickGraphics *pointerClick)
{
    return new PowerController(power, playerLink, pointerClick);
}

// destructor
PowerController::~PowerController()
{

}


// getter y setter
PowerManager::PowerEnum PowerController::getPower() const
{
    return power;
}

Players* PowerController::getPlayerLink() const
{
    return playerLink;
}

ClickGraphics* PowerController::getPointerClick() const
{
    return pointerClick;
}

void PowerController::setPower(PowerManager::PowerEnum power)
{
    this->power = power;
}

void PowerController::setPlayerLink(Players *playerLink)
{
    this->playerLink = playerLink;
}

void PowerController::setPointerClick(ClickGraphics *pointerClick)
{
    this->pointerClick = pointerClick;
}
