#include <iostream>
#include <string>
#include "file.cpp"

int main(int argc, char ** argv)
{
	ReadFile* rFile = new ReadFile();
	std::string temp;
	temp = rFile->FileToString();
	valueRes result;	
	result = rFile->WordsFromFile(temp);
	rFile->Final(result.res, result.size);
	delete rFile;

	return 0;
}
