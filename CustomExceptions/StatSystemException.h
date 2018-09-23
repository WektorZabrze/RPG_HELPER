#ifndef RPGHELPERPROJECT_STATSYSTEMEXCEPTION_H
#define RPGHELPERPROJECT_STATSYSTEMEXCEPTION_H

#include <stdexcept>
#include <string>


/*! \brief Custom exception class.
 *
 *  Custom exception designed to be used when dealing with
 *  methods and classes connected with statistic systems.
 */
class StatSystemException : public std::runtime_error {
public:

    StatSystemException (const std::string& message)
        : std::runtime_error(message.c_str()) {}

    const char* what() const throw() override {
        return std::runtime_error::what();
    }
};


#endif //RPGHELPERPROJECT_STATSYSTEMEXCEPTION_H
