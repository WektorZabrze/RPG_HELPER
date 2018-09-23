//
// Created by arkad on 11.09.2018.
//

#ifndef RPGHELPERPROJECT_STATISTIC_H
#define RPGHELPERPROJECT_STATISTIC_H

#include <string>
#include "StatisticTemplate.h"

/// Class representing single statistic that can be used
/// to describe object in game.
class Statistic : public StatisticTemplate {
public:

    /// Constructor of Statistic object. It takes two arguments - first one
    /// is StatisticTemplate that contains information about statistic (name
    /// and description). Second one is statistics value.
    Statistic (const StatisticTemplate& statTemplate, float value = 0.0f);

    /// Simple getter - returns stat value. Does not allow class user to modify
    /// stored value.
    float GetStatValue() const;

    /// Simple setter method - allows changing stored stat value.
    void SetStatValue(float newValue);

private:

    /// Stores stat value.
    float statValue;
};


#endif //RPGHELPERPROJECT_STATISTIC_H
