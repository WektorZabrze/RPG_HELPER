//
// Created by arkad on 14.09.2018.
//

/// This file contains implementations of methods from
/// StatSystem class.

#include "StatSystem.h"


StatSystem::StatSystem(const StatSystemTemplate& baseStatTemplate)
{
    auto statTemplatesCollection = baseStatTemplate.GetStatList();
    for(auto& statTemplate: statTemplatesCollection)
    {
        Statistic addedStatistic(statTemplate);
    }
}

void StatSystem::SetStatisticValue(const std::string& statName, float statValue)
{
    auto statToChange = GetStatisticWithGivenName(statName);
    if (statToChange == statisticsStoredInSystem.end())
    {
        throw StatSystemException("Statistic named " + statName + " does not exist. ");
    }

    statToChange->SetStatValue(statValue);
}

const std::vector<Statistic>& StatSystem::GetListOfStatistics() const
{
    return statisticsStoredInSystem;
}

std::vector<Statistic>::iterator
    StatSystem::GetStatisticWithGivenName(const std::string& statName)
{
    return std::find_if(statisticsStoredInSystem.begin(), statisticsStoredInSystem.end(),
                        [statName](const Statistic& checked)
                        {
                            return checked.GetName() == statName;
                        });
}
