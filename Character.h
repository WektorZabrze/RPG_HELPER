//
// Created by arkad on 15.09.2018.
//

#ifndef RPGHELPERPROJECT_CHARACTER_H
#define RPGHELPERPROJECT_CHARACTER_H

#include <string>
#include "StatisticsRelatedClasses/StatSystem.h"
#include "StatisticsRelatedClasses/StatSystemTemplate.h"

/// This class defines single in-game character - it can be
/// both playable and NPC one. Character has his statistic
/// system that contains all his/her stats, bio that contains
/// information like lore (basically all information that can
/// be stored using std::string), name nad inventory (to store
/// items).
class Character {
public:

    void SetCharactersName(const std::string& newCharacterName)
    {
        characterName = newCharacterName;
    }

    const std::string& GetCharacterName() const
    {
        return characterName;
    }


private:

    std::string characterName = "";



};


#endif //RPGHELPERPROJECT_CHARACTER_H
