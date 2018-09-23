#include "TextInfoWithOptionsTemplate.h"

#include <algorithm>
#include <stdexcept>

void TextInfoWithOptionsTemplate::AddNewPossibleValue(const std::string& newValue)
{
    if(FindValueInCollection(newValue) != possibleValues.end())
    {
        throw std::runtime_error(
                "Value " + newValue +
                " already added to list of possible ones.");
    }
    possibleValues.push_back(newValue);
}


void TextInfoWithOptionsTemplate::DeletePossibleValue(const std::string& valueToDelete)
{
    auto foundValue = FindValueInCollection(valueToDelete);
    if (foundValue == possibleValues.end())
    {
        throw std::runtime_error(
                "Value " + valueToDelete +
                " does not exist in stored collection so it could not be removed.");
    }
    possibleValues.erase(foundValue);
}


std::vector<std::string>::iterator TextInfoWithOptionsTemplate::FindValueInCollection(
        const std::string& valueToCheck)
{
    return std::find(possibleValues.begin(), possibleValues.end(), valueToCheck);
}