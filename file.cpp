#include "file.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    return result;
}


std::string ReadFile:: WordsFromFile(std::string strFile)
{
    std::string line = strFile;
    std::istringstream ss(line); 
    int size = 0;

    do { 

        std::string word; 
        ss >> word; 
        size++;

        char separator [27] = "[](){}<>\'\",;:*=#!?|\\~@$%^&";
        for (int i = 0; i < 26; i++)
        {
            int leng = word.length();
            if (word[leng-1] == separator[i])
                word = word.replace((word.length()-1), (word.length()), "" );
        }

        std::cout << word << std::endl; 
  
    } while (ss); 
    
    std::string words [size];

    do { 
        std::string word; 
        ss >> word; 
        


        std::cout << word << std::endl; 
  
    } while (ss); 

    
    return " ";
} 
 