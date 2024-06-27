//
// Created by Rashel on 17/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include <stdexcept>

class DeckFileNotFound : public std::exception
{
public:
    explicit DeckFileNotFound() = default;
    ~DeckFileNotFound() override = default;
    const char* what() const noexcept override{ return "Deck File Error: File not found";}
};

class DeckFileFormatError : public std::runtime_error
{
public:
    explicit DeckFileFormatError(const std::string &message) :
            std::runtime_error("Deck File Error: File format error in line "+ message){}
    ~DeckFileFormatError() override = default;
};

class DeckFileInvalidSize : public std::exception
{
public:
    explicit DeckFileInvalidSize() = default;
    ~DeckFileInvalidSize() override = default;
    const char* what() const noexcept override{ return "Deck File Error: Deck size is invalid"; }
};

class InvalidClass : public std::exception
{
public:
    explicit InvalidClass() = default;
    ~InvalidClass() override = default;
    const char* what() const noexcept override{ return "Invalid Class name"; }
};

class InvalidName : public std::exception
{
public:
    explicit InvalidName() = default;
    ~InvalidName() override = default;
    const char* what() const noexcept override{ return "Invalid name - Use english letters only,"
                                                       " maximum length is 15 characters"; }
};



#endif //EX4_EXCEPTION_H
