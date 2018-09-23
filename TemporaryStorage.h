//
// Created by arkad on 12.09.2018.
//

#ifndef RPGHELPERPROJECT_TEMPORATYSTORAGE_H
#define RPGHELPERPROJECT_TEMPORATYSTORAGE_H

#include <vector>
#include "StatisticsRelatedClasses/Statistic.h"
#include "StatisticsRelatedClasses/StatSystemTemplate.h"
#include "TextInfoRelatedClasses/TextInfoSystemTemplate.h"

class TemporaryStorage {

public:
    static std::vector<StatSystemTemplate> createdStatSystemTemplates;
    static std::vector<TextInfoSystemTemplate> createdTextInfoSystemTemplates;
};


#endif //RPGHELPERPROJECT_TEMPORATYSTORAGE_H
