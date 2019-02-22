//
// Created by jjcie on 06.10.2018.
//

#ifndef RPG_HELPER_GAMEFACTORY_H
#define RPG_HELPER_GAMEFACTORY_H

#include "GameEventEnum.h"
#include "IGameEvent.h"
#include "GameEvent.h"
#include "GameEventOptions.h"
#include <memory>

class GameEventFactory {
public:
    std::shared_ptr<IGameEvent> CreateGameEvent(const GameEventEnum& type);

private:

};


#endif //RPG_HELPER_GAMEFACTORY_H
