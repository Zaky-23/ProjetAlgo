#include "../incl/utils.hpp"

std::set<size_t> FindIntersections(Tree** Root, const std::string& Key1, const std::string& Key2)
{
	std::set<size_t> WordOneOcc = GetNode(Root, Key1)->Occurences;
	std::set<size_t> WordTwoOcc = GetNode(Root, Key2)->Occurences;

	std::set<size_t> Intersection;
	// Brute forcing that bitch just like the ape that I am
	for(const size_t& posOne : WordOneOcc)
	{
		for(const size_t& posTwo : WordTwoOcc)
		{
			if(posOne == posTwo)
				Intersection.insert(posOne);
		}
	}

	return Intersection;
}

std::set<size_t> FindPosOccurences(const std::vector<std::string>& Phrases, const std::string& Word)
{
	std::set<size_t> Result;
	size_t Iterator = 1;

	for(const std::string& phrase : Phrases)
	{
		size_t Pos = phrase.find(Word);
		if(Pos != std::string::npos)
		{
			Result.insert(Iterator);
		}

		if(phrase == " ") continue;
		Iterator++;
	}

	return Result;
}