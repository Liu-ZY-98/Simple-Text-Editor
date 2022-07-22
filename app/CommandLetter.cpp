#include "CommandLetter.hpp"

void CommandLetter::newLetter(char key)
{
    letter = key;
}

void CommandLetter::execute(EditorModel& model)
{
    beforeColumnNumber = model.cursorColumn();
    beforeLineNumber = model.cursorLine();
    beforeLineContent = model.returnLineContent(beforeLineNumber);

    std::string beforeCursor = beforeLineContent.substr(0, beforeColumnNumber - 1);
    std::string afterCursor = beforeLineContent.substr(beforeColumnNumber - 1, beforeLineContent.length());
    std::string newLine = beforeCursor + letter + afterCursor;

    model.setCursorColumn(beforeColumnNumber + 1);
    model.changeLineContent(beforeLineNumber, newLine);
}

void CommandLetter::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
    model.changeLineContent(beforeLineNumber, beforeLineContent);
}