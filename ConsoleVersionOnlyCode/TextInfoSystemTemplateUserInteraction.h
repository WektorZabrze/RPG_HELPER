#ifndef RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATEUSERINTERACTION_H
#define RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATEUSERINTERACTION_H

#include "../TextInfoRelatedClasses/TextInfoSystemTemplate.h"
#include "../TextInfoRelatedClasses/TextInfoWithOptionsTemplate.h"
#include "../TextInfoRelatedClasses/TextInfoWithoutOptionsTemplate.h"
#include "UserInputHandlers/ConsoleValueGetter.h"
#include "../TemporaryStorage.h"
#include <iostream>

/*! \brief Handles interaction with user while creating or editing
 *  instance of TextInfoSystemTemplate.
 *
 *  Class designed to be used in console version of RPG Helper. It is
 *  responsible for handling user interaction connected to editing and
 *  creating TextInfoSystemTemplate objects. It provides static methods
 *  that handle operations like adding new TextInfoTemplate, deleting
 *  existing one and changing name of the whole system. It contains two
 *  public methods for handling creation and edition of system template.
 *  This class can not have instance - it is designed to be static library
 *  that can be used from any point where it is needed.
 */
class TextInfoSystemTemplateUserInteraction final {
public:

    /*!
     *  Prevent creating instance of this class.
     */
    TextInfoSystemTemplateUserInteraction() = delete;

    /*! \brief Creates new TextInfoSystemTemplate, manages interaction
     *  with user.
     *
     *  This static method is responsible for creating new instance of
     *  TextInfoSystemTemplate. It handles all user interaction necessary
     *  for doing so via Console. User can choose name for created system
     *  as well as add new TextInfoTemplates to it and delete existing ones.
     *  Template can then be saved to allow its usage in object creation.
     */
    static void CreateSystemTemplate();


    /*! \brief Allows editing existing TextInfoSystemTemplate, manages user
     *  interaction during the process.
     *
     *  This static method is responsible for editing existing instance
     *  of TextInfoSystemTemplate. It handles all necessary interaction
     *  with user via Console. User can change system's name, add and
     *  delete TextInfoTemplates and save result.
     *  \param templateToEdit Reference to TextInfoSystemTemplate user
     *  wants to edit.
     */
    static void EditSystemTemplate(TextInfoSystemTemplate& templateToEdit);

private:

    /*! \brief Prints welcome message when creating new template.
     *
     *  This static method is responsible for printing welcome message
     *  to user via Console when creating new TextInfoSystemTemplate.
     *  This message contains information about creation process.
     */
    static void PrintCreationWelcomeMessage();


    /*! \brief Prints all possible editing options.
     *
     *  This static method is responsible for printing all possible editing
     *  options for user via Console. Currently there are four options:
     *  add new text information, delete existing one, change name of
     *  edited TextInfoSystemTemplate and save changes.
     */
    static void PrintAvailableOptions();


    /*! \brief Prints information about edited TextInfoSystemTemplate.
     *
     *  This static method is responsible for printing information about
     *  currently edited TextInfoSystemTemplate. It prints template name
     *  and all added TextInfoTemplates - their names and descriptions.
     *  \param templateToPrint System template to print detail about.
     */
    static void PrintTextInfoSystemTemplateInformation(
            const TextInfoSystemTemplate& templateToPrint);


    /*! \brief Creates new TextInfoTemplate and adds it to edited instance
     *  of TextInfoSystemTemplate.
     *
     *  This static method is responsible for creating new TextInfoTemplate
     *  and adding it to collection stored in templateToEdit. This method
     *  asks user to provide name and description for created template and
     *  tries to add it to collection - if template with the same name
     *  already exists there, new one is not added and proper information
     *  is printed to Console.
     *  \param templateToEdit TextInfoSystemTemplate where caller wants to
     *  add created TextInfoTemplate.
     */
    static void CreateAndAddNewTextInfo(TextInfoSystemTemplate& templateToEdit);


    /*! \brief Creates new TextInfoWithOptionsTemplate and adds it to edited
     *  instance of TextInfoSystemTemplate.
     *
     *  This static method is responsible for creating new instance of
     *  TextInfoWithOptionsTemplate and adding it to collection stored in
     *  templateToEdit. This method asks user to provide name of description
     *  of created template as well as add new value options to it. Template
     *  then is then added t collection - if template with same name does not
     *  already exist there. It if does, new one is not added and proper
     *  information is printed to Console.
     *  \param templateToEdit TextInfoSystemTemplate where caller wants to
     *  add created TextInfoTemplate.
     */
    static void CreateAndAddNewTextInfoWithLimitedValueOptions(TextInfoSystemTemplate& templateToEdit);

    /*! \brief Deletes existing TextInfoTemplate from specified instance of
     *  TextInfoSystemTemplate
     *
     *  This static method is responsible for deleting TextInfoTemplate from
     *  templateToEdit. This method asks user for name of template to delete.
     *  If such TextInfoTemplate does not exist in templateToEdit, warning
     *  message is displayed and no further action is taken.
     *  \param templateToEdit TextInfoSystemTemplate where caller wants to
     *  delete TextInfoTemplate.
     */
    static void DeleteExistingTextInfo(TextInfoSystemTemplate& templateToEdit);


    /*! Sets new name of TextInfoSystemTemplate instance.
     *
     *  This static method is responsible for setting name of existing
     *  TextInfoSystemTemplate. It asks user for providing proper name
     *  via Console.
     *  \param templateToEdit TextInfoSystemTemplate where caller wants to
     *  set new name.
     */
    static void SetSystemName(TextInfoSystemTemplate& templateToEdit);

};


#endif //RPGHELPERPROJECT_TEXTINFOSYSTEMTEMPLATEUSERINTERACTION_H
