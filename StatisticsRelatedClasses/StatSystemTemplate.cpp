//
// Created by arkad on 11.09.2018.
//

/// This file contains implementations of methods from
/// StatSystemTemplate.

#include <algorithm>
#include "StatSystemTemplate.h"
#include "../CustomExceptions/StatSystemException.h"


void StatSystemTemplate::AddNewStat(const StatisticTemplate& addedStatTemplate)
{
    if (FindStatisticWithGivenName(addedStatTemplate.GetName()) == statsTemplates.end())
    {
        throw StatSystemException(
                "Statistic named " + addedStatTemplate.GetName() + " already exists.");
    }
    statsTemplates.push_back(addedStatTemplate);
}


void StatSystemTemplate::DeleteStatWithGivenName(const std::string& statToDeleteName)
{
    auto statToDelete = FindStatisticWithGivenName(statToDeleteName);
    if (statToDelete != statsTemplates.end())
    {
        throw StatSystemException("Statistic named " + statToDeleteName + " does not exist.");
    }
    statsTemplates.erase(statToDelete);
}


const std::string& StatSystemTemplate::GetName() const
{
    return statSystemTemplateName;
}


void StatSystemTemplate::SetName(const std::string& newName)
{
    statSystemTemplateName = newName;
}


const std::vector<StatisticTemplate>& StatSystemTemplate::GetStatList() const
{
    return statsTemplates;
}


std::vector<StatisticTemplate>::iterator
    StatSystemTemplate::FindStatisticWithGivenName(const std::string& name)
{
    return std::find_if(statsTemplates.begin(), statsTemplates.end(),
                        [name] (StatisticTemplate& statTemp)
                        {
                            return statTemp.GetName() == name;
                        });
}