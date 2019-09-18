#include <iostream>
#include <string>
#include "file.cpp"

int main(int argc, char ** argv)
{
	ReadFile* rFile = new ReadFile("text.txt");
	std::string temp;
	temp = rFile->FileToString();
	rFile->WordsFromFile(temp);
	delete rFile;

	return 0;
}
