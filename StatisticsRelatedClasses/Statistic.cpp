//
// Created by arkad on 11.09.2018.
//

/// This file contains method implementations for Statistic class.

#include "Statistic.h"

Statistic::Statistic (const StatisticTemplate& statTemplate, float value) :
    StatisticTemplate(statTemplate.GetName(), statTemplate.GetDescription()), statValue(value)
{

}


float Statistic::GetStatValue() const
{
    return statValue;
}


void Statistic::SetStatValue(float newValue)
{
    statValue = newValue;
}
