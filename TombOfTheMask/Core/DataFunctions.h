#pragma once
#include "Core/CoreMinimal.h"
#include <fstream>

// –абота с параметрами, которые передаютс€ между игровыми окнами
inline void ChangeDataParamater(std::string key, int NewParamater)
{
    std::ifstream fileIn(RESOURCES_PATH + "GameData.txt");
    assert(fileIn.is_open());

    std::vector<std::string> lines;
    std::string line;
    bool keyIsFounded = false;
    while (std::getline(fileIn, line))
    {
        if (line.find(key) == 0)
        {
            line = key + std::to_string(NewParamater);
            keyIsFounded = true;
        }
        lines.push_back(line);
    }
    fileIn.close();

    if (!keyIsFounded)
        lines.push_back(key + std::to_string(NewParamater));

    std::ofstream fileOut(RESOURCES_PATH + "GameData.txt");
    for (auto &line : lines)
        fileOut << line << '\n';
}
inline int GetDataParameter(std::string key)
{
    std::ifstream fileIn(RESOURCES_PATH + "GameData.txt");

    std::string line;
    while (std::getline(fileIn, line))
    {
        if (line.find(key) == 0)
            return std::stoi(line.substr(key.length()));
    }
    // обработка, если key - ошибка
    return -1;
}