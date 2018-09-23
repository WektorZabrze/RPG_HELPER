//
// Created by arkad on 14.09.2018.
//

#ifndef RPGHELPERPROJECT_STATSYSTEM_H
#define RPGHELPERPROJECT_STATSYSTEM_H

#include <algorithm>
#include <vector>
#include "Statistic.h"
#include "StatSystemTemplate.h"
#include "../CustomExceptions/StatSystemException.h"

/// Class responsible for holding statistic system -
/// named collection of statistics with their values.
class StatSystem {
public:

    /// Statistic system constructor that creates statistic system
    /// using existing template.
    StatSystem(const StatSystemTemplate& baseStatTemplate);

    /// Method that sets value of statistic with specified name stored
    /// in statistic system. If such statistic does not exist, exception
    /// with appropriate message is thrown.
    void SetStatisticValue(const std::string& statName, float statValue);

    /// Method that returns immutable collection of Statistics stored
    /// in StatSystem.
    const std::vector<Statistic>& GetListOfStatistics() const;

private:

    /// Method that returns iterator that points to statistic with given
    /// name stored in statistics system. If no such statistic has been
    /// found, this method returns iterator that points to position after
    /// last element in collection of statistics - end().
    std::vector<Statistic>::iterator GetStatisticWithGivenName(const std::string& statName);

    /// Vector that stores collection of all statistics stored in system.
    std::vector<Statistic> statisticsStoredInSystem;
};


#endif //RPGHELPERPROJECT_STATSYSTEM_H
