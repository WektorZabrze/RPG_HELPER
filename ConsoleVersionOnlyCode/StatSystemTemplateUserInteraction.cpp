#include <iostream> /// std::cout

#include "StatSystemTemplateUserInteraction.h"
#include "../TemporaryStorage.h"

/// Public methods:

void StatSystemTemplateUserInteraction::CreateStatSystemTemplate()
{
    StatSystemTemplate newTemplate;
    PrintWelcomeMessage();
    SetStatSystemTemplateName(newTemplate);
    EditStatSystemTemplate(newTemplate);
}


void StatSystemTemplateUserInteraction::EditStatSystemTemplate(StatSystemTemplate& templateToEdit)
{
    while (true)
    {
        PrintTemplateInformation(templateToEdit);
        PrintAvailableOptions();
        switch (ConsoleValueGetter::GetIntFromGivenRangeFromUser(1, 4))
        {
            case 1:
                AddNewStatistic(templateToEdit);
                break;
            case 2:
                DeleteExistingStatisticFromSystem(templateToEdit);
                break;
            case 3:
                SetStatSystemTemplateName(templateToEdit);
                break;
            case 4:
                SaveStatSystemTemplateToStorage(templateToEdit);
                return;
            default:
                throw std::exception();
        }
    }
}


/// Private methods:

void StatSystemTemplateUserInteraction::PrintWelcomeMessage()
{
    std::cout << "You are about to create statistic system template. Such "
                 "template contains list of statistic templates and can be "
                 "used to create in-game objects (for example characters) with "
                 "unified statistic system. " << std::endl << std::endl;
}


void StatSystemTemplateUserInteraction::PrintTemplateInformation(StatSystemTemplate& templateToPrint)
{
    std::cout << std::endl;
    std::cout << "Currently template has following name: "
              << templateToPrint.GetName() << std::endl;
    std::cout << "It contains following statistics: " << std::endl;

    for (auto& stat : templateToPrint.GetStatList())
    {
        std::cout << stat.GetName() << ": " << stat.GetDescription() << std::endl;
    }
    std::cout << std::endl;
}


void StatSystemTemplateUserInteraction::PrintAvailableOptions()
{
    std::cout << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Add new statistic. " << std::endl;
    std::cout << "2. Delete existing statistic. " << std::endl;
    std::cout << "3. Change system name. " << std::endl;
    std::cout << "4. Save system and exit. " << std::endl << std::endl;
}


void StatSystemTemplateUserInteraction::AddNewStatistic(StatSystemTemplate& templateToEdit)
{
    while (true)
    {
        std::cout << "Please enter statistic name: ";
        std::string statName = ConsoleValueGetter::GetNotEmptyStringFromUser();
        std::cout << "Please enter statistic description: ";
        std::string statDescription = ConsoleValueGetter::GetNotEmptyStringFromUser();

        try {
            templateToEdit.AddNewStat(StatisticTemplate(statName, statDescription));
            return;
        }
        catch (const std::exception& thrownException) {
            std::cout << "Could not add statistic to template: " << thrownException.what() << std::endl;
            std::cout << "Please enter valid data." << std::endl;
        }
    }
}


void StatSystemTemplateUserInteraction::DeleteExistingStatisticFromSystem(StatSystemTemplate& templateToEdit)
{
    std::cout << "Please enter name of statistic to delete: ";
    std::string statToDeleteName = ConsoleValueGetter::GetNotEmptyStringFromUser();

    try
    {
        templateToEdit.DeleteStatWithGivenName(statToDeleteName);
    }
    catch (const std::exception& thrownException)
    {
        std::cout << "Could not delete statistic named: "
                  << statToDeleteName << " because: " << thrownException.what() << std::endl;
    }

}


void StatSystemTemplateUserInteraction::SetStatSystemTemplateName(StatSystemTemplate& templateToEdit)
{
    std::cout << "Please enter system name: ";
    std::string systemName = ConsoleValueGetter::GetNotEmptyStringFromUser();
    templateToEdit.SetName(systemName);
}


/// PLACEHOLDER
void StatSystemTemplateUserInteraction::SaveStatSystemTemplateToStorage(StatSystemTemplate& templateToSave)
{
    TemporaryStorage::createdStatSystemTemplates.push_back(templateToSave);
}
