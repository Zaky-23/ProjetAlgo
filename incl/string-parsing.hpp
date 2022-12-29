#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

const static std::string ERROR_FLAG = "\u001b[31mErrorCode \u001b[31m";

namespace Parse
{
	std::string ExtractText(const std::string& Path);
	size_t ReplaceTextWith(std::string& Str, const std::string& Pattern, const char With);
	std::set<std::string> SplitString(std::string& Str, char Pattern, bool Debug=false);
	std::set<std::string> ExtractWordsFromFileMod(const std::string& Path, const std::string& Patterns = {'.', ',', ':', ';', '\'', '\n'}, bool Debug=false);
}
