#ifndef RPGHELPERPROJECT_TEXTINFOTEMPLATE_H
#define RPGHELPERPROJECT_TEXTINFOTEMPLATE_H

#include "TextInfoTemplateBase.h"
#include <string>

/*! \brief Encapsulates template of text information with any value.
 *
 *  This class represents one type of TextInfo template. This type
 *  describes TextInfo that can have any value - game master gives
 *  no limitations, for example "lore" information. This class
 *  inherits all possible methods from base TextInfoTemplate.
 */
class TextInfoWithoutOptionsTemplate : public TextInfoTemplateBase {
public:

    /*!
     *  Virtual destructor, does nothing. Needs to be implemented because
     *  of the fact TextInfoTemplate class inherits from abstract class.
     */
    virtual ~TextInfoWithoutOptionsTemplate() {}


};

#endif //RPGHELPERPROJECT_TEXTINFOTEMPLATE_H
