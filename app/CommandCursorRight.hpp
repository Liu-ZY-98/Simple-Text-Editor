#ifndef COMMANDCURSORRIGHT_HPP
#define COMMANDCURSORRIGHT_HPP

#include "Command.hpp"
#include "EditorException.hpp"

class CommandCursorRight : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;

private:
    unsigned int beforeLineNumber;
    unsigned int beforeColumnNumber;
};


#endif