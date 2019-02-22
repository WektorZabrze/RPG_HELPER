//
// Created by jjcie on 06.10.2018.
//

#include "IGameEvent.h"

void IGameEvent::AddPlayer(std::shared_ptr<Player> player) {
    players.push_back(player);
}

