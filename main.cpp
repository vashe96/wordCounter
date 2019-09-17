#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// File read
	char str1;
	char str2[255];
	int i = 0;
	int charsize = 0;

	std::ifstream fin("text.txt");
	while (fin.get(str1))
	{
		str2[i] = str1;
		i++;
		charsize = i;
	}
	fin.close();
	for (i = 0; i < charsize; i++ )
		std::cout << str2[i];
	std::cout << std::endl;
	// File read end

	std::string File = std::string(str2);
	std::cout << File << std::endl;
	int as;
	std::cin>>as;

	return 0;
}
