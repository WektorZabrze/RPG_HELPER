#ifndef RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATE_H
#define RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATE_H


#include <memory>
#include <vector>
#include <string>
#include "TextInfoTemplateBase.h"

/*! \brief Encapsulates collection of TextInfoTemplate objects.
 *
 *  This class represents SystemTemplate that stores collection
 *  of TextInfoTemplate objects. This SystemTemplate can then be
 *  used to create system that stores TextInfo objects. TextInfo
 *  encapsulates information that can be stored as string, like
 *  lore or sex. User of this class can add and delete templates.
 *  Each TextInfoSystemTemplate has name - it can also be edited.
 */
class TextInfoSystemTemplate {

public:

    /*! \brief Adds new TextInfoTemplate to SystemTemplate
     *
     *  This method is responsible for adding new TextInfoTemplate
     *  to TextInfoSystemTemplate. New info template is passed to
     *  this method using std::shared_ptr. If TextInfoTemplate with
     *  the same name already exists in SystemTemplate, exception is
     *  thrown - there can not be two TextInfo objects with same name
     *  in one TextInfoSystemTemplate.
     *  \param infoToAdd std::shared_ptr that points to TextInfo template
     *  user wants to add to SystemTemplate.
     */
    void AddInfoTemplate(std::shared_ptr<TextInfoTemplateBase> infoToAdd);


    /*! \brief Deletes existing TextInfoTemplate from SystemTemplate.
     *
     *  This method is used to remove existing TextInfoTemplate from
     *  TextInfoSystemTemplate. User specifies which TextInfo should be
     *  removed by providing its name. If TextInfoTemplate with such
     *  name couldn't be found in system, exception is thrown.
     *  \param nameToFind Name of TextInfoTemplate to delete from
     *  SystemTemplate.
     */
    void DeleteInfoTemplateWithGivenName(const std::string& nameToFind);

    /*! \brief Returns copy collection of pointer to TextInfoTemplates.
     *
     *  This method returns immutable copy of collection of pointers
     *  (std::shared_ptr) that point to immutable TextInfoTemplates
     *  stored in TextInfoSystemTemplate. It can be used to iterate
     *  over list to get data from it - but it can not change stored
     *  data. If user gets this list and then adds or deletes element
     *  from TextInfoSystemTemplate, list returned previously from this
     *  method will not be changed.
     *  \return Immutable copy of collection of pointer to TextInfoTemplates.
     */
    const std::vector<std::shared_ptr<const TextInfoTemplateBase>> GetListOfInfoTemplates() const;

    /*! \brief Sets name of TextInfoSystemTemplate.
     *
     *  Simple setter method that allows to specify new name of existing
     *  TextInfoSystemTemplate.
     *  \param newName String with new name.
     */
    inline void SetSystemName(const std::string& newName) {
        systemName = newName;
    }

    /*! \brief Gets name of TextInfoSystemTemplate.
     *
     *  Simple getter method that returns reference to immutable string
     *  that represents name of TextInfoSystemTemplate.
     *  \return Reference to immutable name.
     */
    inline const std::string& GetSystemName() const noexcept {
        return systemName;
    }


private:

    /*! \brief Gets iterator that allows access to TextInfoTemplate with
     *  specified name.
     *
     *  Private method that returns iterator that points to shared_ptr
     *  that stores TextInfoTemplate with specified name. If it does not
     *  exists, this method returns collectionOfInfo.end() - so it can be
     *  used to check if such element exists.
     *  \param nameToFind Reference to immutable string that stores name of
     *  TextInfoTemplate user wants to get.
     *  \return Iterator that points to shared_ptr to found TextInfoTemplate.
     *  collectionOfInfo.end() if such element does not exist.
     */
    std::vector<std::shared_ptr<TextInfoTemplateBase>>::iterator
        GetInfoTemplateWithGivenName(const std::string& nameToFind);

    /*! \brief Stores name of TextInfoSystemTemplate.
     *
     *  Private field that stores name of TextInfoSystemTemplate. One can
     *  access this field using proper getter and setter methods.
     */
    std::string systemName;

    /*! \brief Stores collection of smart pointers that hold TextInfoTemplates.
     *
     *  Private field that stored collection of std::shared_ptr's that hold
     *  TextInfoTemplates encapsulated by TextInfoSystemTemplate. User can
     *  add new templates to this collection, delete existing one and iterate
     *  over its immutable copy.
     */
    std::vector<std::shared_ptr<TextInfoTemplateBase>> collectionOfInfo;

};


#endif //RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATE_H
