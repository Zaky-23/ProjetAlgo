#include <iostream>
#include <string>
#include <fstream>

#include "../incl/string-parsing.hpp"

int main()
{
	const std::string FILE_PATH = "input/sample.txt";
	const std::string PATTERNS = "\"'.,:;\n!?";
	const std::string WARNING(""
		"******************************************************\n"
		"THIS PROGRAM DOES NOT DETECT UNICODE/SPECIALCHARACTERS\n"
		"PLEASE VERIFY THE INPUT FILE BEFORE PROCEDING\n"
		"******************************************************");

	std::cout << WARNING << '\n';

	std::set<std::string> ParsedWords = Parse::ExtractWordsFromFileMod(FILE_PATH, PATTERNS);

	Parse::PrintWords(ParsedWords);

	return 0;
}