#ifndef COMMANDDELETELINE_HPP
#define COMMANDDELETELINE_HPP

#include "Command.hpp"
#include "EditorException.hpp"
#include <string>

class CommandDeleteLine : public Command
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