#ifndef RPGHELPERPROJECT_TEXTINFO_H
#define RPGHELPERPROJECT_TEXTINFO_H

#include "TextInfoWithoutOptionsTemplate.h"

class TextInfo : public TextInfoWithoutOptionsTemplate {
public:

    TextInfo(const TextInfoWithoutOptionsTemplate& baseTemplate, const std::string& textInfoValue = "")
    {
        infoName = baseTemplate.GetName();
        infoDescription = baseTemplate.GetDescription();
        infoName = textInfoValue;
    }

    void SetInfoValue(const std::string& newValue) {
        infoValue = newValue;
    }

    const std::string& GetInfoValue() const {
        return infoValue;
    }

private:

    std::string infoValue;

};


#endif //RPGHELPERPROJECT_TEXTINFO_H
