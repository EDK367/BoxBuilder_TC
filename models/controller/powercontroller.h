#ifndef POWERCONTROLLER_H
#define POWERCONTROLLER_H
#include "../../models/players.h"
#include "../enum/powermanager.h"
#include "../../utils/clickgraphics.h"

class PowerController
{
    PowerManager::PowerEnum power;
    Players *playerLink;
    ClickGraphics *pointerClick;

    // uso de factory method
    PowerController(PowerManager::PowerEnum power, Players *playerLink, ClickGraphics *pointerClick);


public:
    ~PowerController();

    // factory method estatico para el puntero
    static PowerController *createController(PowerManager::PowerEnum power = PowerManager::PowerEnum::NONE, Players *playerLink = nullptr, ClickGraphics *pointerClick = nullptr);


    PowerManager::PowerEnum getPower() const;
    Players *getPlayerLink() const;
    ClickGraphics *getPointerClick() const;

    void setPower(PowerManager::PowerEnum power);
    void setPlayerLink(Players *playerLink);
    void setPointerClick(ClickGraphics *pointerClick);
};

#endif // POWERCONTROLLER_H
