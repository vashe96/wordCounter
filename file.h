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
    std::string WordsFromFile(std::string); 

private:
    std::string fileName;
};