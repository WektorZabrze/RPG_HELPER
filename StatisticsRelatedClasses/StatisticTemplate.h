//
// Created by arkad on 11.09.2018.
//

#ifndef RPGHELPERPROJECT_STATISTICTEMPLATE_H
#define RPGHELPERPROJECT_STATISTICTEMPLATE_H

#include <string>

/// This class represents statistic's template. Statistic's
/// template is collection of data that describe one particular
/// statistic, but does not contain stat value. User can for
/// example create template for statistic named "Speed" and
/// give it some description. This template can be later used
/// to add "Speed" statistic to some object in game, where it
/// will have it's value.
class StatisticTemplate {
public:

    /// Public constructor of StatisticTemplate. It takes two arguments, but one
    /// of them is optional. First argument represents name of statistic that
    /// will be described by this template. Second argument represents description
    /// of statistic. This constructor simply initializes object fields - it has no
    /// other functionality.
    explicit StatisticTemplate (std::string name, std::string description = "" );

    /// Simple getter method that returns name of statistic template.
    /// Name is returned by value so this method can not be used to
    /// modify stored information.
    std::string GetName() const;

    /// Simple setter method that allows class user to modify one of
    /// its properties - name of statistic that this template describes.
    void SetName(const std::string& newName);

    /// Simple getter method that returns description of statistic template.
    /// Description is returned by value so this method can not be used to
    /// modify stored information.
    std::string GetDescription() const;

    /// Simple setter method that allows class user to modify one of its
    /// properties - description of statistic that this template represents.
    void SetDescription(const std::string& newDescription);

protected:
    /// Stores statistic name
    std::string statName;

    /// Stores statistic description
    std::string statDescription;
};


#endif //RPGHELPERPROJECT_STATISTICTEMPLATE_H
