//
// Created by arkad on 11.09.2018.
//

#ifndef RPGHELPERPROJECT_STATSYSTEMTEMPLATE_H
#define RPGHELPERPROJECT_STATSYSTEMTEMPLATE_H

#include <vector>
#include "StatisticTemplate.h"


/// Class designed to represent system of statistic templates.
/// This template is then used to create real StatSystem that
/// contains statistic values and can be assigned to object in
/// game.
class StatSystemTemplate {
public:

    /// Method responsible for adding new statistic template
    /// to stat system template. Since system can contain
    /// only one template named certain way, it checks whether
    /// statistic with similar name already exists - if yes, then
    /// this method throws exception and does not add statistic.
    void AddNewStat(const StatisticTemplate& addedStatTemplate);

    /// Method responsible for deleting statistic with certain
    /// name from StatSystemTemplate. If statistic with specified
    /// name does not exist, this method throws exception.
    void DeleteStatWithGivenName(const std::string& statToDeleteName);

    /// Method that returns name of StatSystemTemplate it was called
    /// on. Guarantees that name will not be changed - returns it by
    /// const reference.
    const std::string& GetName() const;

    /// Method that allows setting statistic system template name.
    /// It accepts one argument that contains const reference to
    /// new name.
    void SetName(const std::string& newName);

    /// Method that returns collection of statistic templates stored
    /// it system it was called on. Guarantees that this collection
    /// will not be modified - returns it via const reference.
    const std::vector<StatisticTemplate>& GetStatList() const;

private:

    /// Method returns iterator that points to statistic template with
    /// given name stored in StatSystemTemplate. If such stat does not
    /// exist, returns statsTemplates.end() - iterator that points one
    /// to position after last element in collection of all statistic
    /// templates.
    std::vector<StatisticTemplate>::iterator FindStatisticWithGivenName(const std::string& name);

    /// Collection of all statistic templates stored in StatSystemTemplate.
    /// Implemented in a way that preserves statistics order.
    std::vector<StatisticTemplate> statsTemplates;

    /// Field that stored name of statistic system template.
    std::string statSystemTemplateName;
};


#endif //RPGHELPERPROJECT_STATSYSTEMTEMPLATE_H
