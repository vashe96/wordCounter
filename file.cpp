#include "file.h"
#include <iostream>
#include <fstream>

ReadFile::ReadFile()
{
    std::cout << "Enter file name pls: ";
    std::cin >> fileName;
};
ReadFile::ReadFile(std::string fName):
    fileName(fName)
{   
};

std::string ReadFile::SetName(std::string name)
{
    fileName = name;
    return fileName;
}

void ReadFile::GetName()
{
    std::cout << fileName << std::endl;
}

std::string ReadFile::FileToString()
{
   
    std::ifstream myReadFile(fileName);
    std::string result = "";
    char temp;
    while (myReadFile.get(temp)) //reading characters one by one and adding them to result string
    {
        int i = 0;
        result += temp;
        i++;
    }
    myReadFile.close();
    std::cout << result;
    return "dsad";
}