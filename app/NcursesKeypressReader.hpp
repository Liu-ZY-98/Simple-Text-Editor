// NcursesKeypressReader.hpp
//
// ICS 45C Fall 2018
// Project #4: People Just Love to Play with Words
//
// This is a derived class of KeypressReader, which reads keypresses from
// the keyboard using a library called "ncurses".
//
// DO NOT MODIFY THIS FILE

#ifndef NCURSESKEYPRESSREADER_HPP
#define NCURSESKEYPRESSREADER_HPP

#include "KeypressReader.hpp"



class NcursesKeypressReader : public KeypressReader
{
public:
    virtual Keypress nextKeypress() override;
};



#endif // NCURSESKEYPRESSREADER_HPP

