#pragma once

#include <iostream>

class InvalidConfigurationException : public std::exception {
private:
    std::string m_error {};
public:
    InvalidConfigurationException(std::string error);

    const char* what() const noexcept;  
};