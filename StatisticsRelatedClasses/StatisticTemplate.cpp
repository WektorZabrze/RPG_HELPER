//
// Created by arkad on 11.09.2018.
//

/// This file contains method implementations for StatisticTemplate
/// class.

#include "StatisticTemplate.h"

StatisticTemplate::StatisticTemplate (std::string name, std::string description) :
    statName(name), statDescription(description)
{

}


std::string StatisticTemplate::GetName() const
{
    return statName;
}


void StatisticTemplate::SetName(const std::string& newName)
{
    statName = newName;
}


std::string StatisticTemplate::GetDescription() const
{
    return statDescription;
}


void StatisticTemplate::SetDescription(const std::string& newDescription)
{
    statDescription = newDescription;
}