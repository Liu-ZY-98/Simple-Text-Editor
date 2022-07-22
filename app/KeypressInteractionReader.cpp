// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2018
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"

#include "CommandCursorRight.hpp"
#include "CommandCursorLeft.hpp"
#include "CommandCursorDown.hpp"
#include "CommandCursorUp.hpp"
#include "CommandNewLine.hpp"
#include "CommandDeleteLine.hpp"
#include "CommandHome.hpp"
#include "CommandEnd.hpp"
#include "CommandBackspace.hpp"
#include "CommandLetter.hpp"
// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        Command* command = nullptr;
        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            case 'O':
                command = new CommandCursorRight();
                return Interaction::command(command);
            case 'U':
                command = new CommandCursorLeft();
                return Interaction::command(command);
            case 'K':
                command = new CommandCursorDown();
                return Interaction::command(command);
            case 'I':
                command = new CommandCursorUp();
                return Interaction::command(command);
            case 'J':
                command = new CommandNewLine();
                return Interaction::command(command);
            case 'M':
                command = new CommandNewLine();
                return Interaction::command(command);
            case 'D':
                command = new CommandDeleteLine();
                return Interaction::command(command);
            case 'Y':
                command = new CommandHome();
                return Interaction::command(command);
            case 'P':
                command = new CommandEnd();
                return Interaction::command(command);
            case 'H':
                command = new CommandBackspace();
                return Interaction::command(command);
            default:
                break;
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            char key = keypress.code();
            CommandLetter *letter = new CommandLetter();
            letter -> newLetter(key);
            Command *command = letter;
            return Interaction::command(command);
        }
    }
}

