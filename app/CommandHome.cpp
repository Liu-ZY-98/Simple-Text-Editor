#include "CommandHome.hpp"

void CommandHome::execute(EditorModel& model)
{
    beforeColumnNumber = model.cursorColumn();
    model.setCursorColumn(1);
}

void CommandHome::undo(EditorModel& model)
{
    model.setCursorColumn(beforeColumnNumber);
}