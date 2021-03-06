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
#include "OutOfBoundsException.hpp"

namespace
{
    unsigned int init_cap = 0;    
} 

String::String()
    :word{new char[init_cap]},char_count{0}
{
}

String::String(const char* chars)
{
    
    unsigned int size = 0;
    while (chars[size] !='\0') size++;
    String::char_count = size;
    char* the_char = new char[size];
    for (unsigned int i = 0; i< size;++i)
    {  
        the_char[i] = chars[i];
    }
    this->word = the_char;
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


void String::append(const String& s)
{   
    // char* s_array = new char[s.char_count];
    // for (unsigned int i=0; i< s.char_count;++i)
    // {
    //     s_array[i] = s.word[i];
    // }

    int new_size = this->char_count+s.char_count;
    char* new_array = new char[new_size]; // 5 + 6 old + append
    for (unsigned int i = 0; i<this->char_count;++i)
    {
        new_array[i] = this->word[i];
    }
    for (unsigned int i = 0; i<s.char_count; ++i)
    {
        new_array[i+this->char_count] = s.word[i];
    }

    this->word = new_array;
    this->char_count = new_size;

}

char String::at(unsigned int index) const
{

    // try
    // {
    //     if (index>=0 && index <this->char_count)
    //     {
    //         return this->word[index];
    //     }
    //     else
    //     {
    //         throw Out
    //     }
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    if (index>=0 && index <this->char_count)
    {
        return this->word[index];
    }
    else
    {
        throw OutOfBoundsException();
    }
    
}


char& String::at(unsigned int index)
{   
    if (index>=0 && index <this->char_count)
    {
        return this->word[index];
    }
    else
    {
        throw OutOfBoundsException();
    }
    
}


void String::clear()
{
    this->char_count = 0;

    this->word = new char[0];
}


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
