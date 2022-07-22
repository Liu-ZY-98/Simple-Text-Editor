#ifndef COMMANDLETTER_HPP
#define COMMANDLETTER_HPP

#include "Command.hpp"
#include <string>

class CommandLetter : public Command
{
public:
    void newLetter(char key);
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    unsigned int beforeColumnNumber;
    unsigned int beforeLineNumber;
    char letter;
    std::string beforeLineContent;
};

#endif