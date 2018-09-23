#ifndef RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGINTERFACE_H
#define RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGINTERFACE_H

#include "TextInfoWithOptionsTemplate.h"
#include <memory>

/*! \brief Interface for editing classes.
 *
 *  This class serves as interface for classes responsible for handling
 *  user interaction when trying to edit TextInfoWithOptionsTemplate.
 *  It can then be implemented by in various versions of project - for
 *  example to edit via Console or GUI.
 */
class TextInfoWithOptionsTemplateEditingInterface
{
public:

    /*! \brief Interaction with user when editing template with value options.
     *
     *
     *  \param templateToEdit Template caller wants to edit using implementation
     *  of this interface.
     */
    virtual void Edit(std::shared_ptr<TextInfoWithOptionsTemplate> templateToEdit) = 0;

};


#endif //RPGHELPERPROJECT_TEXTINFOWITHOPTIONSTEMPLATEEDITINGINTERFACE_H
