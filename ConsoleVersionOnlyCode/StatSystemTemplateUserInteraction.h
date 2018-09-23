//
// Created by arkad on 12.09.2018.
//

#ifndef RPGHELPERPROJECT_STATSYSTEMTEMPLATECREATION_H
#define RPGHELPERPROJECT_STATSYSTEMTEMPLATECREATION_H

#include "../StatisticsRelatedClasses/StatSystemTemplate.h"
#include "UserInputHandlers/ConsoleValueGetter.h"

/// Class designed to be used in Console Version of RPGHelper
/// project. It provides methods that handle interaction
/// between program and user when user requests StatSystemTemplate
/// creation or editing. StatSystemTemplate contains list of stats with
/// their values that can be reused to create many objects
/// with same stat system. This class uses std::cout to print
/// information to Console. All methods in this class are static
/// to avoid need of creating instance of this object.
class StatSystemTemplateUserInteraction{

public:

    /// Constructor of StatSystemTemplateCreation is disabled - this
    /// class contains only static methods so there is no need to
    /// create its instance.
    StatSystemTemplateUserInteraction() = delete;

    /// This method is designed to be main way of creating new
    /// StatSystemTemplate objects in Console version of RPGHelper.
    /// Handles interaction with user while he/she provides information
    /// about new StatSystemTemplate.
    static void CreateStatSystemTemplate();

    /// This method is designed to be main way of editing existing
    /// StatSystemTemplate object in Console version of RPGHelper.
    static void EditStatSystemTemplate(StatSystemTemplate& templateToEdit);

private:

    /// Static method that prints StatSystemTemplate creation welcome
    /// message to Console using std::cout. Welcome message contains
    /// instructions for user about creation process.
    static void PrintWelcomeMessage();

    /// Static method that prints information about existing
    /// StatSystemTemplate. Printed information consist of
    /// StatSystemTemplate name and stored StatTemplates -
    /// names and descriptions.
    static void PrintTemplateInformation(StatSystemTemplate& templateToPrint);

    /// Static method that prints all options that user can
    /// choose when creating or editing StatSystemTemplate.
    /// User can for example add new StatTemplate, delete
    /// existing one or change systems name.
    static void PrintAvailableOptions();

    /// Static method responsible for one of actions user can
    /// choose to perform on created/edited StatSystemTemplate.
    /// Gets input needed to create and add new statistic template.
    /// Prints information using std::cout. Calls method from
    /// StatSystemTemplate responsible for adding new statistic
    /// template.
    static void AddNewStatistic(StatSystemTemplate& templateToEdit);

    /// Static method responsible for one of actions user can
    /// choose to perform on created/edited StatSystemTemplate.
    /// Gets name of statistic user wants to delete form existing
    /// StatSystemTemplate and calls method responsible for deleting
    /// this statistic from template if it exists.
    static void DeleteExistingStatisticFromSystem(StatSystemTemplate& templateToEdit);

    /// Static method responsible for one of actions user can
    /// choose to perform on created/edited StatSystemTemplate.
    /// Allows user to specify new name of StatSystemTemplate.
    static void SetStatSystemTemplateName(StatSystemTemplate& templateToEdit);

    /// PLACEHOLDER - MODIFY WHEN DB INTERFACE AVAILABLE
    /// Static method responsible for one of actions user can
    /// choose to perform on created/edited StatSystemTemplate.
    /// Saves template to storage.
    static void SaveStatSystemTemplateToStorage(StatSystemTemplate& templateToSave);
};


#endif //RPGHELPERPROJECT_STATSYSTEMTEMPLATECREATION_H
