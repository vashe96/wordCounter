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
    char str1 = ' ';	
	int i = 0;
	int charsize = 0;

	std::ifstream fin(fileName);
	while (fin.get(str1)) //checking size of file
	{
		i++;
		charsize = i;
	}

    char resultString[charsize]; //create array of symbols from file 
    while (fin.get(str1)) 
        {
            resultString[i] = str1;
            i++;
        }

	fin.close();

	std::cout << charsize << std::endl;
    std::string result = std::string (resultString);
    std::cout << result << std::endl;
    return result;
}