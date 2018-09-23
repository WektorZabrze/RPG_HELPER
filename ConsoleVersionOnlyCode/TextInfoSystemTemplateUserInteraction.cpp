#include "TextInfoSystemTemplateUserInteraction.h"


void TextInfoSystemTemplateUserInteraction::CreateSystemTemplate()
{
    PrintCreationWelcomeMessage();
    TextInfoSystemTemplate newTemplate;
    SetSystemName(newTemplate);
    EditSystemTemplate(newTemplate);
}


// TODO: Think about using command pattern in this method
void TextInfoSystemTemplateUserInteraction::EditSystemTemplate(
        TextInfoSystemTemplate& templateToEdit)
{
    void (*availableMethods[])(TextInfoSystemTemplate&) = {
            CreateAndAddNewTextInfo,
            CreateAndAddNewTextInfoWithLimitedValueOptions,
            DeleteExistingTextInfo,
            SetSystemName};

    while (true)
    {
        PrintTextInfoSystemTemplateInformation(templateToEdit);
        PrintAvailableOptions();
        int userChoice = ConsoleValueGetter::GetIntFromGivenRangeFromUser(1, 5);

        if (userChoice == 5)
        {
            TemporaryStorage::createdTextInfoSystemTemplates.push_back(templateToEdit);
            return;
        }

        availableMethods[userChoice - 1](templateToEdit);
    }
}


void TextInfoSystemTemplateUserInteraction::PrintCreationWelcomeMessage()
{
    std::cout << "You are going to create template of system that \n"
                 "stores text information about object in game. \n"
                 "Such information include race, sex and lore. \n"
                 "You will be able to add new information template and \n"
                 "edit or delete existing ones. " << std::endl << std::endl;
}


void TextInfoSystemTemplateUserInteraction::PrintAvailableOptions()
{
    std::cout << "Please choose what would you like to do: " << std::endl;
    std::cout << "1. Add new text information. " << std::endl;
    std::cout << "2. Add new text information with limited value options. " << std::endl;
    std::cout << "3. Delete existing information." << std::endl;
    std::cout << "4. Change system's name. " << std::endl;
    std::cout << "5. Save and exit. " << std::endl << std::endl;
}


void TextInfoSystemTemplateUserInteraction::PrintTextInfoSystemTemplateInformation(
        const TextInfoSystemTemplate& templateToPrint)
{
    std::cout << "Template name: " << templateToPrint.GetSystemName() << std::endl;
    std::cout << "Information: " << std::endl;
    for (auto& storedInfo : templateToPrint.GetListOfInfoTemplates())
    {
        std::cout << storedInfo->GetName() << ": " << storedInfo->GetDescription() << std::endl;
    }
    std::cout << std::endl;

}

// TODO: Move to separate class, refactor
void TextInfoSystemTemplateUserInteraction::CreateAndAddNewTextInfo(
        TextInfoSystemTemplate& templateToEdit)
{
    std::shared_ptr<TextInfoTemplateBase> newTextInfo (new TextInfoWithoutOptionsTemplate);
    try
    {
        std::cout << "Please enter information name: ";
        std::string informationName = ConsoleValueGetter::GetNotEmptyStringFromUser();
        newTextInfo->SetName(informationName);
        std::cout << "Please enter information description: ";
        std::string informationDescription = ConsoleValueGetter::GetNotEmptyStringFromUser();
        newTextInfo->SetDescription(informationDescription);
        templateToEdit.AddInfoTemplate(newTextInfo);
    }
    catch (std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
}

// TODO: Move editing and creation to separate classes, reduce amount of redundant code.
void TextInfoSystemTemplateUserInteraction::CreateAndAddNewTextInfoWithLimitedValueOptions(
        TextInfoSystemTemplate& templateToEdit)
{
    std::shared_ptr<TextInfoTemplateBase> newTextInfo (new TextInfoWithOptionsTemplate);
    try
    {
        templateToEdit->
        templateToEdit.AddInfoTemplate(newTextInfo);
    }
    catch (std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
}


void TextInfoSystemTemplateUserInteraction::DeleteExistingTextInfo(
        TextInfoSystemTemplate& templateToEdit)
{
    try
    {
        std::cout << "Please enter proper text information name: ";
        std::string textInfoName = ConsoleValueGetter::GetNotEmptyStringFromUser();
        templateToEdit.DeleteInfoTemplateWithGivenName(textInfoName);
    }
    catch(std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
}


void TextInfoSystemTemplateUserInteraction::SetSystemName(TextInfoSystemTemplate& templateToEdit)
{
    std::cout << "Please enter valid name for information system: ";
    std::string newSystemName = ConsoleValueGetter::GetNotEmptyStringFromUser();
    templateToEdit.SetSystemName(newSystemName);
}