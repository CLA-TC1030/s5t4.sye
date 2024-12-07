#pragma once

#include <iostream>

class InvalidOptionException : public std::exception {
private:
    std::string m_error {};
public:
    InvalidOptionException(std::string error);

    const char* what() const noexcept;  
};