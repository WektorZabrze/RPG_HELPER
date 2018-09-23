#include "TextInfoSystemTemplate.h"
#include <algorithm>


void TextInfoSystemTemplate::AddInfoTemplate(std::shared_ptr<TextInfoTemplateBase> infoToAdd)
{
    if (GetInfoTemplateWithGivenName(infoToAdd->GetName()) != collectionOfInfo.end())
    {
        throw std::runtime_error(
                "Information named " + infoToAdd->GetName()
                + " already exists. Can not add same information twice.");
    }
    collectionOfInfo.emplace_back(infoToAdd);
}


void TextInfoSystemTemplate::DeleteInfoTemplateWithGivenName(const std::string& nameToFind)
{
    auto foundInfo = GetInfoTemplateWithGivenName(nameToFind);
    if (foundInfo == collectionOfInfo.end())
    {
        throw std::runtime_error(
                "Information named " + nameToFind
                + " does not exists, so it can't be deleted.");
    }
    collectionOfInfo.erase(foundInfo);
}


const std::vector<std::shared_ptr<const TextInfoTemplateBase>>
    TextInfoSystemTemplate::GetListOfInfoTemplates() const
{
    std::vector<std::shared_ptr<const TextInfoTemplateBase>> collectionCopy;
    for (auto& textInfoPtr : collectionOfInfo)
    {
        collectionCopy.emplace_back(textInfoPtr);
    }
    return collectionCopy;
}


std::vector<std::shared_ptr<TextInfoTemplateBase>>::iterator
    TextInfoSystemTemplate::GetInfoTemplateWithGivenName(const std::string& nameToFind)
{
    auto nameChecker = [&nameToFind] (std::shared_ptr<TextInfoTemplateBase> ptrToCheck)
    {
        return ptrToCheck->GetName() == nameToFind;
    };

    return std::find_if(
            collectionOfInfo.begin(),
            collectionOfInfo.end(),
            nameChecker);

}