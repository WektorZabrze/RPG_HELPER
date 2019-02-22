//
// Created by jjcie on 06.10.2018.
//

#include "GameEventFactory.h"

std::shared_ptr<IGameEvent> GameEventFactory::CreateGameEvent(const GameEventEnum &type) {
    if(type == GameEventEnum ::Options){
        return std::make_shared<GameEventOptions>(new GameEventOptions());
    }
}