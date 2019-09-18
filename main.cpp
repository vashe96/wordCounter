#include <iostream>

#include <string>

#include "file.cpp"

int main(int argc, char ** argv)
{
	ReadFile* rFile = new ReadFile("text.txt");

	rFile->FileToString();
	delete rFile;

	return 0;
}
