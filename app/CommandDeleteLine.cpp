#include "CommandDeleteLine.hpp"

void CommandDeleteLine::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();
    beforeLineCount = model.lineCount();
    beforeLineContent = model.returnLineContent(beforeLineNumber);

    if (beforeLineContent.length() > 0 and beforeLineCount == 1)
    {
        model.setCursorLine(1);
        model.setCursorColumn(1);
        model.deleteLine(beforeLineNumber);
    }
    else if (beforeLineCount > 1)
    {
        if (beforeLineNumber == beforeLineCount)
        {
            model.setCursorLine(beforeLineNumber - 1);
            int prevLine = model.returnLineContent(beforeLineNumber - 1).length() + 1;
            if (prevLine < beforeColumnNumber)
            {
                model.setCursorColumn(prevLine);
            }
            model.deleteLine(beforeLineNumber);
        }
        else
        {
            int afterLine = model.returnLineContent(beforeLineNumber + 1).length() + 1;
            if (afterLine < beforeColumnNumber)
            {
                model.setCursorColumn(afterLine);
            }
            model.deleteLine(beforeLineNumber);
        }
        model.setLineCount(beforeLineCount - 1);
    }
    else
    {
        throw EditorException("Already empty");
    }
}

void CommandDeleteLine::undo(EditorModel& model)
{
    if (beforeLineCount > 1)
    {
        model.setLineCount(beforeLineCount);
    }
    model.addNewLine(beforeLineNumber, beforeLineContent);
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}