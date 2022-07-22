#include "CommandEnd.hpp"

void CommandEnd::execute(EditorModel& model)
{
    beforeColumnNumber = model.cursorColumn();
    beforeLineNumber = model.cursorLine();
    model.setCursorColumn(model.returnLineContent(beforeLineNumber).length() + 1);
}

void CommandEnd::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
}