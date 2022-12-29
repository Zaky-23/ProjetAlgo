#include <iostream>
#include <string>
#include <fstream>

#include "../incl/string-parsing.hpp"



int main()
{
	const char* FILE_PATH = "input/sample.txt";
	const char PATTERNS[] = {'.', ',', ':', ';', '\n', '!', '?'};

	auto v = Parse::ExtractWordsFromFileMod(FILE_PATH, PATTERNS, true);

	std::vector<std::string> Buffer;

	for(auto& e : v)
	{
		std::cout << e;
	}

	// for(auto& e : v)
	// {
	// 	std::cout << e << '\n';
	// }

	return 0;
}