#include "CommandNewLine.hpp"

void CommandNewLine::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();
    beforeLineCount = model.lineCount();
    beforeLineContent = model.returnLineContent(beforeLineNumber);

    unsigned int addLineNumber = beforeLineNumber + 1;
    std::string beforeCursor, afterCursor;

    if (beforeColumnNumber == beforeLineContent.length() + 1)
    {
        std::string empty;
        model.addNewLine(addLineNumber, empty);
    }
    else if (beforeColumnNumber < beforeLineContent.length() + 1)
    {
        afterCursor = beforeLineContent.substr(beforeColumnNumber - 1, beforeLineContent.length());
        beforeCursor = beforeLineContent.substr(0, beforeColumnNumber - 1);
        model.addNewLine(addLineNumber, afterCursor);
        model.changeLineContent(beforeLineNumber, beforeCursor);
    }
    model.setLineCount(beforeLineCount + 1);
    model.setCursorLine(addLineNumber);
    model.setCursorColumn(1);
}

void CommandNewLine::undo(EditorModel& model)
{
    model.deleteLine(beforeLineNumber + 1);
    model.changeLineContent(beforeLineNumber, beforeLineContent);
    model.setLineCount(beforeLineCount);
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}