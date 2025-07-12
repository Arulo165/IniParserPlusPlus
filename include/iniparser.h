#pragma once

#include <string>


class parser
{
public:
    std::string searchValueOfKey(std::string path, std::string key);
    void setValueOfKey(std::string path, std::string key, std::string value);
};