#include "CommandCursorRight.hpp"

void CommandCursorRight::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();
    
    if (beforeColumnNumber <= model.returnLineContent(beforeLineNumber).length())
    {
        model.setCursorColumn(beforeColumnNumber + 1);
    }
    else if ((beforeColumnNumber == model.returnLineContent(beforeLineNumber).length()+1)
                and (beforeLineNumber < model.lineCount()))
    {
        model.setCursorColumn(1);
        model.setCursorLine(beforeLineNumber + 1);
    }
    else
    {
        throw(EditorException("Already at end"));
    }
}

void CommandCursorRight::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}