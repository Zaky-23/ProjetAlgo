#include <iostream>
#include <string>
#include <fstream>

#include "../incl/string-parsing.hpp"
#include "../incl/tree.hpp"
#include "../incl/utils.hpp"


int main()
{
	const std::string FILE_PATH("input/sample.txt");
	const std::string PATTERNS("\".,:;\n!?");

	std::vector<std::string> ParsedPhrases = Parse::ExtractPhrasesFromFile(FILE_PATH);
	std::set<std::string> ParsedWords = Parse::ExtractWordsFromFile(FILE_PATH, PATTERNS);

	Tree** Root = nullptr;
	Tree* FirstNode = CreateNode("");
	Root = &FirstNode;

	for(const auto& word : ParsedWords)
	{
		std::set<size_t> WordOccurenes = FindPosOccurences(ParsedPhrases, word);
		InsertNode(Root, word, WordOccurenes);
	}

	std::string InputBuffer;
	std::cout << "Commands:\n" 
	<< "!(q)uit: To quit\n"
	<< "!(e)xist: To check if a word exists\n"
	<< "!(f)ind: To research the phrase(s) where a word occured\n"
	<< "!(i)ntersction: To check the intersection of two words\n";

	while (true)
	{
		std::cin >> InputBuffer;

		if(InputBuffer == "!q" || InputBuffer == "!quit")
			break;

		else if(InputBuffer == "!f" || InputBuffer == "!find")
		{
			std::cout << "Enter the word you want to search: ";
			std::cin >> InputBuffer;

			Tree* Node = GetNode(Root, InputBuffer);

			if(Node == nullptr)
			{
				std::cout << "This word does not exist" << '\n';
				continue;
			}

			for(const size_t& pos : Node->Occurences)
			{
				std::cout << pos << ' ';
			}

			std::cout << '\n';
			continue;
		}

		else if(InputBuffer == "!e" || InputBuffer == "!exist")
		{
			std::cout << "Enter the word you want to check: ";
			std::cin >> InputBuffer;

			Tree* Temp = GetNode(Root, InputBuffer);

			if(Temp == nullptr){
				std::cout << "This word does not exist" << '\n';
				continue;
			}
			
			std::cout << "This word exists" << '\n';
		}

		else if(InputBuffer == "!i" || InputBuffer == "!intersection")
		{
			std::cout << "Enter the first word: ";
			std::string Word1;
			std::cin >> Word1;

			if(GetNode(Root, Word1) == nullptr)
			{
				std::cout << "The word (" << Word1 << ") does not exist" << '\n';
				continue;
			}

			std::cout << "Enter the second word: ";
			std::string Word2;
			std::cin >> Word2;

			if(GetNode(Root, Word2) == nullptr)
			{
				std::cout << "The word (" << Word2 << ") does not exist" << '\n';
				continue;
			}

			std::set<size_t> Intersections = FindIntersections(Root, Word1, Word2);

			if(Intersections.size() == 0)
			{
				std::cout << "There are no intersections" << '\n';
				continue;
			}

			std::cout << "The words intersect at phrase(s) number: ";

			for(size_t pos : Intersections)
			{
				std::cout << pos << ' ';
			}

			std::cout << '\n';
		}

		else 
		{
			std::cout << "Unknow command\n";
		}
	}

	return 0;
}