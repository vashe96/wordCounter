#include "file.h"
#include <iostream>
#include <fstream>
#include <sstream>

Result::Result(){word = ""; count = 0;}
Result::Result(std::string w, int c) {word = w; count = c;}

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

void ReadFile::Final(std::string* array, int size)
{
    int len = size;
    std::string* str  = new std::string[len];
    str = array;
    

    Result* res1 = new Result[size];


    for (int i = 0; i < len; i++)
    {
        int count = 0;
        res1[i].word = str[i];
        for (int j = 0; j < len; j++)
        {
            if(res1[i].word == str[j]) res1[i].count++;
        }
        std::cout << res1[i].word << " " << res1[i].count << std::endl;
    }
    
    for (int i = 0; i < len; i++)
    {
        std::string temp = res1[i].word;
        for (int j = i+1; j < len; j++)
        {
            std::string temp2 = res1[j].word;
            if (temp == temp2)
            {
                for (int k = j+1; k < len; k++)
                    {   
                        res1[k-1].word = res1[k].word;
                        res1[k-1].count = res1[k].count;
                        res1[k].word = " ";
                        res1[k].count = 0;
                    }
            }
        }
        std::cout << res1[i].word << " " << res1[i].count << std::endl;
    
    }
    
    
      for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (res1[j].count < res1[j + 1].count) {
                Result temp = res1[j];
                res1[j] = res1[j + 1];
                res1[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        std::cout << res1[i].word << " " << res1[i].count << std::endl;
    }
    
  }

 