#ifndef COMMANDEND_HPP
#define COMMANDEND_HPP

#include "Command.hpp"

class CommandEnd : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    unsigned int beforeColumnNumber;
    unsigned int beforeLineNumber;
};

#endif