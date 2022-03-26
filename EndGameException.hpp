#pragma once

#include <iostream>

class EndGameException : public std::exception {
private:
    std::string m_error {};
public:
    EndGameException(std::string error);

    const char* what() const noexcept;  
};