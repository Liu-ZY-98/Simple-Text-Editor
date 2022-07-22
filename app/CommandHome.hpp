#ifndef COMMANDHOME_HPP
#define COMMANDHOME_HPP

#include "Command.hpp"

class CommandHome : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    unsigned int beforeColumnNumber;
};

#endif