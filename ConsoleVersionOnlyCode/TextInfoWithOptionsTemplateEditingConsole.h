
#ifndef RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGCONSOLE_H
#define RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGCONSOLE_H

#include "../TextInfoRelatedClasses/TextInfoWithOptionsTemplateEditingInterface.h"
#include "UserInputHandlers/ConsoleValueGetter.h"
#include <algorithm>
#include <iostream>

class TextInfoWithOptionsTemplateEditingConsole : public TextInfoWithOptionsTemplateEditingInterface {
public:

    void Initialize(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        ChangeTextInfoTemplateName(templateToEdit);
        ChangeTextInfoTemplateDescription(templateToEdit);
        while (true)
        {
            try
            {
                std::cout << "What would you like to do? " << std::endl;
                std::cout << "1. Add new allowed value. " << std::endl;
                std::cout << "2. Delete existing value" << std::endl;
                std::cout << "3. Save and exit. " << std::endl;

                int userChoice = ConsoleValueGetter::GetIntFromGivenRangeFromUser(1, 3);
                if (userChoice == 3)
                {
                    return;
                }

                if (userChoice == 1)
                {
                    AddNewAllowedValue(templateToEdit);
                }
                else
                {
                    DeleteExistingAllowedValue(templateToEdit);
                }
            }
            catch (std::exception& exception)
            {
                std::cout << exception.what() << std::endl;
            }
        }
    }

    void Edit(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        PrintInformationAboutEditedTemplate(templateToEdit);
        PrintAvailableEditingOptions();

        // TODO: Consider using Command pattern
        void (TextInfoWithOptionsTemplateEditingConsole::*availableOptions[])(
                std::shared_ptr<TextInfoWithOptionsTemplate>) = {
                &TextInfoWithOptionsTemplateEditingConsole::ChangeTextInfoTemplateName,
                &TextInfoWithOptionsTemplateEditingConsole::ChangeTextInfoTemplateDescription,
                &TextInfoWithOptionsTemplateEditingConsole::AddNewAllowedValue,
                &TextInfoWithOptionsTemplateEditingConsole::DeleteExistingAllowedValue};

        while(true)
        {
            int userChoice = ConsoleValueGetter::GetIntFromGivenRangeFromUser(1, 5);
            if (userChoice == 5)
            {
                return;
            }
            (this->*availableOptions[userChoice - 1])(templateToEdit);
        }
    }

private:

    void PrintInformationAboutEditedTemplate(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit) const
    {
        std::cout << templateToEdit->GetName() << std::endl;
        std::cout << templateToEdit->GetDescription() << std::endl;
        std::cout << "Possible text option values: ";
        auto possibleValues = templateToEdit->GetListOfPossibleValues();
        std::for_each(
                possibleValues.begin(),
                possibleValues.end(),
                [](const std::string& value) { std::cout << " - " << value << std::endl; }
                );

    }

    void PrintAvailableEditingOptions() const
    {
        std::cout << "You can do one of following things: " << std::endl;
        std::cout << "1. Change information's name. " << std::endl;
        std::cout << "2. Change information's description" << std::endl;
        std::cout << "3. Add new allowable value. " << std::endl;
        std::cout << "4. Delete existing value. " << std::endl;
        std::cout << "5. Save and exit. " << std::endl << std::endl;
    }

    void ChangeTextInfoTemplateName(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        std::cout << "Please enter information's name: ";
        std::string newName = ConsoleValueGetter::GetNotEmptyStringFromUser();
        templateToEdit->SetName(newName);
    }

    void ChangeTextInfoTemplateDescription(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        std::cout << "Please enter information's description: ";
        std::string newDescription = ConsoleValueGetter::GetNotEmptyStringFromUser();
        templateToEdit->SetDescription(newDescription);
    }


    void AddNewAllowedValue(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        try
        {
            std::cout << "Please enter new value: ";
            std::string newValue = ConsoleValueGetter::GetNotEmptyStringFromUser();
            templateToEdit->AddNewPossibleValue(newValue);
        }
        catch (std::exception& exception)
        {
            std::cout << exception.what() << std::endl;
        }
    }

    void DeleteExistingAllowedValue(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit)
    {
        try
        {
            std::cout << "Please enter value to delete: ";
            std::string valueToDelete = ConsoleValueGetter::GetNotEmptyStringFromUser();
            templateToEdit->DeletePossibleValue(valueToDelete);
        }
        catch (std::exception& exception)
        {
            std::cout << exception.what() << std::endl;
        }


    }


};


#endif //RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGCONSOLE_H
