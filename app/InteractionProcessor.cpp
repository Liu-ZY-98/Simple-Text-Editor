// InteractionProcessor.cpp
//
// ICS 45C Fall 2018
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    std::vector<Command*> undoStack;
    std::vector<Command*> redoStack;
    std::vector<Command*> allCommands;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (undoStack.size() >= 1)
            {
                Command* command = undoStack.at(undoStack.size() - 1);
                try
                {
                    command -> undo(model);
                    redoStack.push_back(command);
                    undoStack.pop_back();
                }
                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                    delete command;
                }
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoStack.size() >= 1)
            {
                Command* command = redoStack.at(redoStack.size() - 1);
                try
                {
                    command -> execute(model);
                    undoStack.push_back(command);
                    redoStack.pop_back();
                }
                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                    delete command;
                }
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                if (command == nullptr)
                {
                    delete command;
                }
                else
                {
                    command->execute(model);
                    undoStack.push_back(command);
                    allCommands.push_back(command);
                    redoStack.clear();
                }
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            
        }
    }
    for (Command* c : allCommands)
    {
        delete c;
    }
}

