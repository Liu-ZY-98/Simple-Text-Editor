#ifndef COMMANDCURSORLEFT_HPP
#define COMMANDCURSORLEFT_HPP

#include "Command.hpp"
#include "EditorException.hpp"

class CommandCursorLeft : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;

private:
    unsigned int beforeLineNumber;
    unsigned int beforeColumnNumber;
};

#endif