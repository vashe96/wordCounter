#include <iostream>
#include <string>
#include "file.cpp"

int main(int argc, char ** argv)
{
	ReadFile* rFile = new ReadFile("text.txt");
	std::string temp;
	temp = rFile->FileToString();
	valueRes result;	
	result = rFile->WordsFromFile(temp);
	rFile->Result(result.res, result.size);
	delete rFile;

	return 0;
}
