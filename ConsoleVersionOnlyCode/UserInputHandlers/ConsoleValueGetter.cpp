#include <algorithm> /// std::find_if, std::all_of
#include <iostream> /// std::cin, std::cout
#include <sstream> /// std::stringstream

#include "ConsoleValueGetter.h"

float ConsoleValueGetter::GetFloatFromUser()
{
    float userInput = 0.0f;

    auto checkIfCharIsOtherThatDigitOrDot = [](char c) {
        return (!std::isdigit(c) && c != '.');
    };

    while (true)
    {
        std::string lineToReadFromUser;
        std::getline(std::cin, lineToReadFromUser);
        std::stringstream inputStringStream(lineToReadFromUser);

        /// Get input from line and check if line contains only
        /// valid characters
        if ((inputStringStream>> userInput) &&
            (std::find_if(
                    lineToReadFromUser.begin(),
                    lineToReadFromUser.end(),
                    checkIfCharIsOtherThatDigitOrDot)
                    == lineToReadFromUser.end()))
        {
            return userInput;
        }

        userInput = 0.0f;
        std::cout << "Wrong input value!. Please enter proper value." << std::endl;
    }
}

int ConsoleValueGetter::GetIntFromUser()
{
    int userInput = 0;

    auto checkIfCharIsOtherThatDigit = [](char c) {
        return !std::isdigit(c);
    };

    while (true)
    {
        std::string lineToReadFromUser;
        std::getline(std::cin, lineToReadFromUser);
        std::stringstream inputStringStream(lineToReadFromUser);

        /// Get input from line and check if line contains only
        /// valid characters
        if ((inputStringStream >> userInput) &&
            (std::find_if(
                    lineToReadFromUser.begin(),
                    lineToReadFromUser.end(),
                    checkIfCharIsOtherThatDigit)
                    == lineToReadFromUser.end()))
        {
            return userInput;
        }

        userInput = 0;
        std::cout << "Wrong input value!. Please enter proper integer value." << std::endl;
    }
}

std::string ConsoleValueGetter::GetNotEmptyStringFromUser()
{
    std::string userInput;
    while (true)
    {
        std::getline(std::cin, userInput);
        if (!std::all_of(userInput.begin(), userInput.end(), std::iswspace))
        {
            return userInput;
        }

        userInput = "";
        std::cout << "Wrong input! Please enter proper text value." << std::endl;
    }
}

int ConsoleValueGetter::GetIntFromGivenRangeFromUser(int lowerBound, int upperBound)
{
    while (true)
    {
        int userInput = GetIntFromUser();

        if (userInput >= lowerBound && userInput <= upperBound)
        {
            return userInput;
        }
        std::cout << "Provided number does not lie in given range." << std::endl;
    }
}

