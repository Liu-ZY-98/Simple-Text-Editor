#include "CommandCursorUp.hpp"

void CommandCursorUp::execute(EditorModel& model)
{
    beforeLineNumber = model.cursorLine();
    beforeColumnNumber = model.cursorColumn();

    if (beforeLineNumber > 1)
    {
        if (model.returnLineContent(beforeLineNumber - 1).length() >= beforeColumnNumber)
        {
            model.setCursorLine(beforeLineNumber - 1);
        }
        else
        {
            model.setCursorLine(beforeLineNumber - 1);
            model.setCursorColumn(model.returnLineContent(beforeLineNumber - 1).length() + 1);
        }
    }
    else
    {
        throw(EditorException("Already at top"));
    }
}

void CommandCursorUp::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
    model.setCursorLine(beforeLineNumber);
}