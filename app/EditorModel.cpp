// EditorModel.cpp
//
// ICS 45C Fall 2018
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
{
}


int EditorModel::cursorLine() const
{
    return lineNumber;
}


int EditorModel::cursorColumn() const
{
    return columnNumber;
}


int EditorModel::lineCount() const
{
    return totalLineNumber;
}


const std::string& EditorModel::line(int lineNumber) const
{
    return lineContents[lineNumber - 1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorLine;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    errorLine = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorLine = "";
}

void EditorModel::setCursorColumn(unsigned int col)
{
    columnNumber = col;
}

void EditorModel::setCursorLine(unsigned int line)
{
    lineNumber = line;
}
void EditorModel::setLineCount(unsigned int lCount)
{
    totalLineNumber = lCount;
}
std::string EditorModel::returnLineContent(unsigned int lineNum)
{
    return lineContents[lineNum - 1];
}
void EditorModel::changeLineContent(unsigned int lineNum, std::string& content)
{
    lineContents[lineNum - 1] = content;
}
void EditorModel::addNewLine(unsigned int lineNum, std::string& content)
{
    lineContents.insert(lineContents.begin() + (lineNum - 1), content);
}
void EditorModel::deleteLine(unsigned int lineNum)
{
    lineContents.erase(lineContents.begin() + (lineNum - 1));
    if (lineContents.size() == 0)
    {
        lineContents.push_back("");
    }
}