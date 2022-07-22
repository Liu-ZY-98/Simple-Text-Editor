#include "CommandBackspace.hpp"

void CommandBackspace::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();
    beforeLineCount = model.lineCount();
    beforeLineContent = model.returnLineContent(beforeLineNumber);

    std::string combine;

    if (beforeLineNumber == 1 and beforeColumnNumber == 1)
    {
        throw EditorException("Already at beginning");
    }
    else if (beforeColumnNumber == 1)
    {
        model.setCursorLine(beforeLineNumber - 1);
        model.setLineCount(beforeLineCount - 1);
        prevLineContent = model.returnLineContent(beforeLineNumber - 1);
        model.setCursorColumn(prevLineContent.length() + 1);
        combine = prevLineContent + beforeLineContent;
        model.changeLineContent(beforeLineNumber - 1, combine);
        model.deleteLine(beforeLineNumber);
    }
    else
    {
        model.setCursorColumn(beforeColumnNumber - 1);
        if (beforeLineNumber == beforeLineContent.length() + 1)
        {
            prevLineContent = beforeLineContent.substr(0, beforeLineContent.length() - 1);
            model.changeLineContent(beforeLineNumber, prevLineContent);
        }
        else
        {
            std::string afterCursor;
            prevLineContent = beforeLineContent.substr(0, beforeColumnNumber - 2);
            afterCursor = beforeLineContent.substr(beforeColumnNumber - 1, beforeLineContent.length());
            combine = prevLineContent + afterCursor;
            model.changeLineContent(beforeLineNumber, combine);
        }
    }
}

void CommandBackspace::undo(EditorModel& model)
{
    if (beforeColumnNumber > 1)
    {
        model.setCursorColumn(beforeColumnNumber);
        model.setCursorLine(beforeLineNumber);
        model.changeLineContent(beforeLineNumber, beforeLineContent);
    }   
    else if (beforeColumnNumber == 1 and beforeLineNumber > 1)
    {
        model.setCursorColumn(beforeColumnNumber);
        model.setCursorLine(beforeLineNumber);
        model.setLineCount(beforeLineNumber);
        model.changeLineContent(beforeLineNumber - 1, prevLineContent);
        model.addNewLine(beforeLineNumber, beforeLineContent);   
    }
}