#include <iostream>

#include <string>

#include "file.cpp"

int main()
{
	ReadFile* rFile = new ReadFile();

	rFile->FileToString();
	delete rFile;

	return 0;
}
