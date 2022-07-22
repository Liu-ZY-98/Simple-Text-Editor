#include "CommandCursorDown.hpp"

void CommandCursorDown::execute(EditorModel& model)
{
    beforeColumnNumber = model.cursorColumn();
    beforeLineNumber = model.cursorLine();

    if ((beforeLineNumber < model.lineCount())
         and (beforeColumnNumber <= model.returnLineContent(beforeLineNumber + 1).length() + 1))
    {
        model.setCursorLine(beforeLineNumber + 1);
    }
    else if ((beforeLineNumber < model.lineCount())
         and (beforeColumnNumber > model.returnLineContent(beforeLineNumber + 1).length() + 1))
    {
        model.setCursorLine(beforeLineNumber + 1);
        model.setCursorColumn(model.returnLineContent(beforeLineNumber + 1).length() + 1);
    }
    else
    {
        throw(EditorException("Already at bottom"));
    }
}

void CommandCursorDown::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}