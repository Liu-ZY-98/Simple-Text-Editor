#ifndef COMMANDNEWLINE_HPP
#define COMMANDNEWLINE_HPP

#include "Command.hpp"
#include <string>

class CommandNewLine : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    unsigned int beforeColumnNumber;
    unsigned int beforeLineNumber;
    unsigned int beforeLineCount;
    std::string beforeLineContent;
};

#endif