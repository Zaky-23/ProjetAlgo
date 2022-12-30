#include "string-parsing.hpp"

std::string Parse::ExtractText(const std::string& Path)
{
	// text a traiter
	std::string Text("");
	// std::ios::in == read_mode
	std::ifstream File;
	// attraper les erreurs
	File.exceptions(std::ios::failbit | std::ios::badbit);
	try {
		File.open(Path, std::ios::in);

		// buffer chaine de caractere
		std::stringstream StringBuffer;
		StringBuffer << File.rdbuf();

		File.close();

		Text = StringBuffer.str();
	} catch(std::ifstream::failure& error) {
		std::cout << ERROR_FLAG << "(" << error.code().value() << "): " << error.code().message() 
		<< " | Category: " << error.code().category().name() << '\n';
		return Text;
	}

	return Text;
}

size_t Parse::ReplaceTextWith(std::string& Str, const std::string& Patterns, const char With)
{
	size_t Iterator = 0;
	size_t ReplacedOccurences = 0;
	std::string NewStr;

	for(const char& pattern : Patterns)
	{
		if(Str.find(pattern) == Str.npos)
		{
			Iterator++;
			continue;
		}

		for( char& character : Str)
		{
			if(character == pattern)
			{
				character = With;
				ReplacedOccurences++;
			}
		}
	}

	return ReplacedOccurences;
}

std::set<std::string> Parse::SplitString(std::string& Str, char Pattern, bool Debug)
{
	std::set<std::string> SplitStr;
	std::string Buffer;

	for( char& character : Str)
	{
		Buffer.push_back(character);

		if(Pattern == character)
		{
			SplitStr.insert(Buffer);
			Buffer.clear();
		}
	}

	return SplitStr;
}

std::set<std::string> Parse::ExtractWordsFromFileMod(const std::string& Path, const std::string& Patterns, bool Debug)
{
	std::string Text = Parse::ExtractText(Path);
	
	size_t NumReplacedChars = Parse::ReplaceTextWith(Text, Patterns, ' ');
	Parse::ReplaceTextWith(Text, Patterns, ' ');
	
	if(Debug)
		std::cout << "Total number of characters replaced: " << NumReplacedChars << '\n';

	std::set<std::string> Result = Parse::SplitString(Text, ' ', Debug);

	return Result;
}

void Parse::PrintWords(std::set<std::string> Words)
{
	for(const std::string& word : Words)
	{
		std::cout << word << '\n';
	}
}