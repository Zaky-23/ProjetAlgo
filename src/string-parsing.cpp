#include "string-parsing.hpp"

std::string Parse::ExtractText(const std::string& Path)
{
	// text a traiter
	std::string Text("");
	// std::ios::in == read_mode
	std::ifstream File;
	// // attraper les erreurs
	// File.exceptions(std::ios::failbit | std::ios::badbit);
	// try {
	// 	File.open(Path, std::ios::in);

	// 	// buffer chaine de caractere
	// 	std::stringstream StringBuffer;
	// 	StringBuffer << File.rdbuf();

	// 	File.close();

	// 	Text = StringBuffer.str();
	// } catch(std::ifstream::failure& error) {
	// 	std::cout << ERROR_FLAG << "(" << error.code().value() << "): " << error.code().message() 
	// 	<< " | Category: " << error.code().category().name() << '\n';
	// 	return Text;
	// }

	File.open(Path, std::ios::in);

	// buffer chaine de caractere
	std::stringstream StringBuffer;
	StringBuffer << File.rdbuf();

	File.close();

	Text = StringBuffer.str();

	return Text;
}

size_t Parse::ReplaceTextWith(std::string& Str, const std::string& Patterns, const char With)
{
	size_t ReplacedOccurences = 0;
	std::string NewStr;

	for(const char& pattern : Patterns)
	{
		if(Str.find(pattern) == Str.npos)
			continue;

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

std::vector<std::string> Parse::SplitString(const std::string& Str, char Pattern)
{
	std::vector<std::string> SplitStr;
	std::string Buffer;

	for( const char& character : Str)
	{
		Buffer.push_back(character);

		if(Pattern == character)
		{
			Buffer.pop_back();
			SplitStr.push_back(Buffer);
			Buffer.clear();
		}
	}

	return SplitStr;
}

std::set<std::string> Parse::ExtractWordsFromFile(const std::string& Path, const std::string& Patterns)
{
	std::string Text = Parse::ExtractText(Path);

	Parse::ReplaceTextWith(Text, Patterns, ' ');

	auto TempResult = Parse::SplitString(Text, ' ');

	std::set<std::string> Result;

	for(const std::string& word : TempResult)
	{
		Result.insert(word);
	}

	return Result;
}

std::vector<std::string> Parse::ExtractPhrasesFromFile(const std::string& Path)
{
	std::string Text = Parse::ExtractText(Path);

	Parse::ReplaceTextWith(Text, ",\n\"", '.');

	auto TempResult = Parse::SplitString(Text, '.');

	std::vector<std::string> Result;

	for(const std::string& word : TempResult)
	{
		Result.push_back(word);
	}

	return Result;
}

void Parse::PrintWords(const std::set<std::string>& Words)
{
	for(const std::string& word : Words)
		std::cout << word << '\n';
}

void Parse::PrintPhrases(const std::vector<std::string>& Phrases)
{
	for(const std::string& phrase : Phrases)
		std::cout << phrase << '\n';
}