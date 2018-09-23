#ifndef RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATE_H
#define RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATE_H

#include "TextInfoTemplateBase.h"
#include <vector>
#include <string>
#include <memory>
#include "TextInfoWithOptionsTemplateEditingInterface.h"
#include "../ConsoleVersionOnlyCode/TextInfoWithOptionsTemplateEditingConsole.h"

/*! \brief Represents text information with limited number of values
 *  template
 *
 *  This class represents one type of TextInfo template. This one
 *  stores collection of possible values TextInfo can have - it can
 *  be used to create for example "race" info, where game master
 *  can specify limited selection of values. This class provides
 *  ways of adding and deleting possible options and getting list
 *  of them.
 */
class TextInfoWithOptionsTemplate : public TextInfoTemplateBase {
public:

    /*! \brief Adds new value to list of possible ones.
     *
     *  This method is responsible for adding new value to collection
     *  of possible TextInfo values. It checks if value already exists -
     *  if it does, throws exception with proper information.
     *  \param newValue Reference to immutable string containing new
     *  value that should be added to collection of possible values.
     */
    void AddNewPossibleValue(const std::string& newValue);

    /*! \brief Deletes value from collection of possible ones.
     *
     *  This method is responsible for deleting existing value from
     *  collection of possible values. It checks if value exists - if
     *  not, throws exception with proper error message.
     *  \param valueToDelete Value to delete from stored collection.
     */
    void DeletePossibleValue(const std::string& valueToDelete);

    /*! \brief Returns collection of possible values
     *
     *  This method is responsible for returning reference to immutable
     *  collection of all values possible for TextInfo.
     *  \return Immutable collection of possible values.
     */
    inline const std::vector<std::string>& GetListOfPossibleValues() const {
        return possibleValues;
    }

    // TODO Finish
    inline void InvodeInitInterface() {
        editingInterface->Edit(this);
    }

private:

    /*! \brief Returns value with given name stored in collection.
     *
     *  This method is responsible for returning iterator that points
     *  to stored value with given name. If such value was not found,
     *  possibleValues.end() is returned.
     *  \param valueToCheck Value to find and return.
     *  \return Iterator to found value or possibleValues.end() if value
     *  was not found.
     */
    std::vector<std::string>::iterator FindValueInCollection(const std::string& valueToCheck);

    /*! \brief Collection of possible TextInfo values.
     *
     *  Vector that stores collection of all values possible for
     *  TextInfo.
     */
    std::vector<std::string> possibleValues;

    std::shared_ptr<TextInfoWithOptionsTemplateEditingInterface> editingInterface;
};


#endif //RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATE_H
