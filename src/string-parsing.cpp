#include "string-parsing.hpp"

std::string ExtractText(const std::string& Path)
{
	std::string Text("");

	std::ifstream File;

	 File.exceptions(std::ios::failbit | std::ios::badbit);
	 try {
	 	File.open(Path, std::ios::in);

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

size_t ReplaceTextWith(std::string& Str, const std::string& Patterns, const char With)
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

std::vector<std::string> SplitString(const std::string& Str, char Pattern)
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

std::set<std::string> ExtractWordsFromFile(const std::string& Path, const std::string& Patterns)
{
	std::string Text = ExtractText(Path);

	ReplaceTextWith(Text, Patterns, ' ');

	auto TempResult = SplitString(Text, ' ');

	std::set<std::string> Result;

	for(const std::string& word : TempResult)
	{
		Result.insert(word);
	}

	return Result;
}

std::vector<std::string> ExtractPhrasesFromFile(const std::string& Path)
{
	std::string Text = ExtractText(Path);

	ReplaceTextWith(Text, ",\n\"", '.');

	auto TempResult = SplitString(Text, '.');

	std::vector<std::string> Result;

	for(const std::string& word : TempResult)
	{
		Result.push_back(word);
	}

	return Result;
}

void PrintWords(const std::set<std::string>& Words)
{
	for(const std::string& word : Words)
		std::cout << word << '\n';
}

void PrintPhrases(const std::vector<std::string>& Phrases)
{
	for(const std::string& phrase : Phrases)
		std::cout << phrase << '\n';
}