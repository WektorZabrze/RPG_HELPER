cmake_minimum_required(VERSION 3.12)
project(RPG_HELPER)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RPG_HELPER
        Action.h
        EPriveleges.h
        Exceptions.h
        Game.h
        GameMaster.h
        Player.h
        test.cpp
        Token.h
        TokenHandler.h
        User.h GameEvents/IGameEvent.cpp GameEvents/IGameEvent.h GameEvents/GameEvent.cpp GameEvents/GameEvent.h GameEvents/GameEventOptions.cpp GameEvents/GameEventOptions.h GameEvents/GameEventChain.cpp GameEvents/GameEventChain.h GameEvents/GameEventFactory.cpp GameEvents/GameEventFactory.h GameEvents/GameEventEnum.h GameEvents/GameEventManager.cpp GameEvents/GameEventManager.h)
