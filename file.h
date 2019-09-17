#include <string>

class ReadFile
{
public:
    ReadFile();
    ReadFile(std::string);
    ~ReadFile(){}; 

    std::string SetName (std::string);
    void GetName();

    std::string FileToString();

private:
    std::string fileName;
};