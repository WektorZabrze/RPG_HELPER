#ifndef RPGHELPERPROJECT_TEXTINFOSYSTEM_H
#define RPGHELPERPROJECT_TEXTINFOSYSTEM_H

#include <memory>
#include <vector>
#include "TextInfo.h"
#include "TextInfoSystemTemplate.h"

class TextInfoSystem {

public:
    TextInfoSystem(const TextInfoSystemTemplate& baseTemplate) {
        for (auto& infoTemplatePtr : baseTemplate.GetListOfInfoTemplates())
        {
            //std::shared_ptr<TextInfo> newInfo (new TextInfo(*infoTemplatePtr));
        }
    }

private:

    std::vector<std::shared_ptr<TextInfo>> collectionOfInformation;

};


#endif //RPGHELPERPROJECT_TEXTINFOSYSTEM_H
