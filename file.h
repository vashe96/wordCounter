#include <string>
class valueRes
{
public:
    valueRes(std::string*, int);
    valueRes();
    std::string* res;
    int size;
};

class ReadFile
{
public:
    ReadFile();
    ReadFile(std::string);
    ~ReadFile(){}; 

    std::string SetName (std::string);
    void GetName();
    
    std::string FileToString();
    valueRes WordsFromFile(std::string); 
    void Result(std::string*, int); 

private:
    std::string fileName;
};