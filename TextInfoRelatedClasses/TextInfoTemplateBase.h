
#ifndef RPGHELPERPROJECT_TEXTINFOTEMPLATEBASE_H
#define RPGHELPERPROJECT_TEXTINFOTEMPLATEBASE_H

#include <string>

/*! \brief Abstract base class for TextInfoTemplate classes.
 *
 *  This class is responsible for encapsulating information
 *  common to all TextInfoTemplate types. Such templates can
 *  then be stored in TextInfoSystemTemplate using interface
 *  provided by this class. TextInfo is a way of describing object
 *  in game - like item or character, and can contain information
 *  such as lore or race. Template stores name and description of
 *  single information - it does not store value - it is stored in
 *  TextInfo itself.
 */
class TextInfoTemplateBase {

public:

    /*! \brief Sets name of text information
     *
     *  Simple setter method that sets new name of text information
     *  stored in template it was called on.
     *  \param newName Immutable string that represents new name.
     */
    inline void SetName(const std::string& newName) {
        infoName = newName;
    }

    /*! \brief Gets immutable name of text information
     *
     *  Simple getter method used to get value of text information
     *  name - returns it as immutable string.
     *  \return Immutable string that contain name of information.
     */
    inline const std::string& GetName() const noexcept {
        return infoName;
    }

    /*! \brief Sets description of text information
     *
     *  Simple setter method that sets new description stored in
     *  text information.
     *  \param newDescription Immutable string representing new
     *  description.
     */
    inline void SetDescription(const std::string& newDescription) {
        infoDescription = newDescription;
    }

    /*! \brief Gets immutable description of text information.
     *
     *  Simple getter method used to get value of text information
     *  description - returns it as immutable string.
     *  \return Immutable string that represents description of
     *  text information.
     */
    inline const std::string& GetDescription() const noexcept {
        return infoDescription;
    }

    inline virtual void InvokeInitInterface() = 0;

    inline virtual void InvokeEditingInterface() = 0;

    virtual ~TextInfoTemplateBase() {}

protected:

    /*! \brief TextInfo name.
     *
     *  Protected variable that stores name of TextInfo in a form of
     *  std::string. To access this variable one should use getter
     *  and setter methods.
     */
    std::string infoName;

    /*! \brief TextInfo description.
     *
     *  Protected variable that stores description of TextInfo in a
     *  form of std::string. To access this variable one should use
     *  proper getter and setter methods.
     */
    std::string infoDescription;
};


#endif //RPGHELPERPROJECT_TEXTINFOTEMPLATEBASE_H
