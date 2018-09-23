/// Main file created for testing purposes

#include <iostream>

#include "ConsoleVersionOnlyCode/UserInputHandlers/ConsoleValueGetter.h"
#include "ConsoleVersionOnlyCode/StatSystemTemplateUserInteraction.h"
#include "ConsoleVersionOnlyCode/TextInfoSystemTemplateUserInteraction.h"

int main() {

    /// ConsoleValueGetter Test

    std::cout << "Please enter proper integer value: " << std::endl;
    int testIntInput = ConsoleValueGetter::GetIntFromUser();
    std::cout << "Int input result: " << testIntInput << std::endl;

    std::cout << "Please enter proper float value: " << std::endl;
    float testFloatInput = ConsoleValueGetter::GetFloatFromUser();
    std::cout << "Float input result: " << testFloatInput << std::endl;

    std::cout << "Please enter proper text value: " << std::endl;
    std::string testStringInput = ConsoleValueGetter::GetNotEmptyStringFromUser();
    std::cout << "String input result: " << testStringInput << std::endl;

    getchar();

    /// StatSystemTemplateCreation Test

    //StatSystemTemplateUserInteraction::CreateStatSystemTemplate();

    /// TextInfoSystemTemplate creation Test

    TextInfoSystemTemplateUserInteraction::CreateSystemTemplate();

    return 0;
}