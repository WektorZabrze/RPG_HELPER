#ifndef RPGHELPERPROJECT_CONSOLEVALUEGETTER_H
#define RPGHELPERPROJECT_CONSOLEVALUEGETTER_H

#include <string>

/*!
 *  This class contains static methods that handle getting
 *  proper input from user via Console. It contains methods
 *  that handle getting proper float, int and string values.
 */
class ConsoleValueGetter {

public:

    /*!
     *  Static method that handles getting proper float value
     *  from user via Console. It checks if user input is correct.
     *  If not, prints proper warning and asks for input again.
     *  \return Proper float value.
     */
    static float GetFloatFromUser();

    /*!
     *  Static method that handles getting proper int value from
     *  user via Console. It validates user input and if it's not
     *  correct, prints proper warning and asks to provide input
     *  again.
     *  \return Proper int value.
     */
    static int GetIntFromUser();

    /*!
     *  Static method that handles getting proper std::string from
     *  user via Console. It validates if string contain anything
     *  more than whitespaces - if not, asks user for input again.
     *  \return Proper string that contain not only whitespaces.
     */
    static std::string GetNotEmptyStringFromUser();

    /*!
     *  Static method that handler getting proper int value that lies
     *  in given range from user via Console. Method arguments represent
     *  lower and upper bound of that range (range includes both bounds).
     *  \param lowerBound Minimal acceptable value.
     *  \param upperBound Maximal acceptable value.
     *  \return Proper int value from given range.
     */
    static int GetIntFromGivenRangeFromUser(int lowerBound, int upperBound);

};


#endif //RPGHELPERPROJECT_CONSOLEVALUEGETTER_H
