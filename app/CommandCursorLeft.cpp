#include "CommandCursorLeft.hpp"

void CommandCursorLeft::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();

    if (beforeColumnNumber > 1)
    {
        model.setCursorColumn(beforeColumnNumber - 1);
    }
    else if ((beforeLineNumber > 1) and (beforeColumnNumber == 1))
    {
        model.setCursorColumn(model.returnLineContent(beforeLineNumber - 1).length() + 1);
        model.setCursorLine(beforeLineNumber - 1);        
    }
    else
    {
        throw(EditorException("Already at beginning"));
    }
}

void CommandCursorLeft::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}