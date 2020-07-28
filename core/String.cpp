// String.cpp
//
// ICS 46 Spring 2020
// Project #0: Getting to Know the ICS 46 VM
//
// Implement all of your String member functions in this file.
//
// Note that the entire standard library -- both the C Standard
// Library and the C++ Standard Library -- is off-limits for this
// task, as the goal is to exercise your low-level implementation
// skills (pointers, memory management, and so on).

#include "String.hpp"

namespace
{
    unsigned int init_cap = 0;    
} 

String::String()
    :word{new char[init_cap]},char_count{0}
{
}

String::String(const char* chars)
    :word{chars}
{
    unsigned int size = 0;
    while (chars[size] !='\0') size++;
    String::char_count = size;
}

String::String(const String& s)
    :word{s.word}, char_count{s.char_count}
{
    
}

String& String::operator=(const String& s)
{
    if (this != &s)
    {
        this->word = s.word;
        this->char_count = s.char_count;
    }
    return *this;
}

String::~String() noexcept
{

}


// void String::append(const String& s)
// {
    
//     this->word += s;
// }

bool String::isEmpty() const noexcept
{
    if (char_count == 0)
    {
        return true;
    }
    return false;
}

unsigned int String::length() const noexcept
{
    return char_count;
}

const char* String::toChars() const noexcept
{
    const char* a_word = String::word;
    return a_word;
}
