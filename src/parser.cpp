#include <iniparser.h>
#include <fstream>
#include <string>
#include <vector>

std::string parser::searchValueOfKey(std::string path, std::string key) 
{

    std::ifstream file(path);

    if(!file.is_open()) 
    {
        return "";
    }
    
    std::string line;
    while(std::getline(file, line)) 
    {
        int pos = line.find('=');

        if (pos == std::string::npos){continue;} 

        if(line.substr(0, pos) == key)
        {
            return line.substr(pos + 1);
        }

    }

    return "";
}

void parser::setValueOfKey(std::string path, std::string key, std::string value) 
{
    std::ifstream file(path);
    std::string line;
    bool keyFound = false;
    std::vector<std::string> lines;

    while (std::getline(file, line)) 
    {
        int pos = line.find('=');

        if (pos != std::string::npos && line.substr(0, pos) == key)
        {
            line = key + "=" + value;
            keyFound = true;
        }

        lines.push_back(line);
    }

    if (!keyFound) {
        lines.push_back(key + "=" + value);
    }

    std::ofstream out(path, std::ios::trunc);

    for (const auto& l : lines) {
        out << l << '\n';
    }
}
