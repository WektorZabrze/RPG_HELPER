//
// Created by jjcie on 06.10.2018.
//

#ifndef RPG_HELPER_GAMEEVENTMANAGER_H
#define RPG_HELPER_GAMEEVENTMANAGER_H

#include "IGameEvent.h"
#include <list>
#include <memory>

class GameEventChain {
public:
    GameEventChain(IGameEvent& initialEvent){
        head.push_back(std::make_unique<IGameEvent>(initialEvent));
    }

    void addEvent(IGameEvent& newEvent){
        head.push_back(std::make_unique<IGameEvent>(newEvent));
    }

    IGameEvent& getLast(){
        return *head.back();
    }

    IGameEvent getFirst(){
        return *head.front();
    }

private:
    std::list<std::unique_ptr<IGameEvent>> head;
};


#endif //RPG_HELPER_GAMEEVENTMANAGER_H