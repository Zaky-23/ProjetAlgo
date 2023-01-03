#include "../incl/tree.hpp"

Tree* CreateNode(const std::string& Value) 
{
	return new Tree {.Right = nullptr, .Left = nullptr, .Key = Value, .Occurences = {0}};
}

void InsertNode(Tree** Root, const std::string& Value, const std::set<size_t>& WordOccurences)
{
	if(Root == nullptr) 
	{
		*Root = CreateNode(Value);
		return;
	}

	Tree* Current = *Root;

	Tree* NewNode = CreateNode(Value);
	NewNode->Occurences = WordOccurences;

	while (1)
	{
		int Difference = Current->Key.compare(Value);

		if(Difference == 0) {
			return;

		} else if(Difference > 0) {
			if(Current->Right == nullptr)
			{
				Current->Right = NewNode;
				return;
			}
			Current = Current->Right;

		} else {
			if(Current->Left == nullptr)
			{
				Current->Left = NewNode;
				return;
			}
			Current = Current->Left;
		}
	}
}

Tree* GetNode(Tree** Root, const std::string& Key)
{	
	if(Root == nullptr) 
	{
		return nullptr;
	}

	Tree* Current = *Root;

	while(Current != nullptr)
	{
		int Difference = Current->Key.compare(Key);

		if(Difference == 0) {
			return Current;

		} else if(Difference > 0) { 
			Current = Current->Right;

		} else {
			Current = Current->Left;

		}
	}

	return Current;
}

void PrintTree(Tree** Root)
{
	Tree* Current = *Root;

	if(Current == nullptr)
	{
		return;
	}

	PrintTree(&Current->Left);
	std::cout << Current->Key << '\n';
	PrintTree(&Current->Right);
}