#include "file.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

valueRes::valueRes(std::string* r, int s) {res = r; size = s;}
valueRes::valueRes() {res = 0; size = 0;}

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




valueRes ReadFile::WordsFromFile (std::string strFile)
{
    std::string line = strFile;
    std::istringstream ss(line); 
    int size = 0;
    do { 

        std::string word; 
        ss >> word;
        size++;
    } while (ss);
    
    std::istringstream ss2(line); 
    std::string* words = new std::string [size];
    int i = 0;
    do { 

        std::string word; 
        ss2 >> word; 

        char separator [27] = "[](){}<>\'\",;:*=#!?|\\~@$%^&";
        for (int i = 0; i < 26; i++)
        {
            int leng = word.length();
            if (word[leng-1] == separator[i])
                word = word.replace((word.length()-1), (word.length()), "" );
        }
       
        words[i] = word;
        i++;
  
    } while (ss2);     
   
    for (int i = 0; i < size; i++)
        std::cout << words[i] << std::endl;
    valueRes res(words, size);
    
    return res;
} 

void ReadFile::Result(std::string* array, int size)
{
    std::string arr  = *array;
    int len = size;

    for (int i = 0; i < len; i++)
    {
        int counter = 0;
        std::string temp = array[i];
        for (int j = 0; j < len; j++)
        {
            if (temp == array[i]) counter++;  
        }
    std::cout << array[i]<< " " << counter << std::endl;
    
  }
}
 