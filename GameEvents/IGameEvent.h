//
// Created by jjcie on 06.10.2018.
//

#ifndef RPG_HELPER_IGAMEEVENT_H
#define RPG_HELPER_IGAMEEVENT_H

#include <string>
#include <vector>
#include "../Player.h"
#include <memory>

struct IGameEvent {
    virtual ~IGameEvent() = default;
    std::string content;
    std::vector<std::shared_ptr<Player>> players;
private:
    void AddPlayer(std::shared_ptr<Player> player);
};


#endif //RPG_HELPER_IGAMEEVENT_H
