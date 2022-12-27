#include "../incl/tree.hpp"

Tree* CreateNode(const std::string& Value) 
{
	return new Tree {.Right = nullptr, .Left = nullptr, .Data = Value};
}

void InsertNode(Tree** Root, const std::string& Value)
{
	if(Root == nullptr) 
	{
		std::cout << "InsertNodeAt(nullptr, \"" << Value << "\"" << "): 'nullptr' Root" << '\n';
		return;
	}

	Tree* Current = *Root;

	Tree* NewNode = CreateNode(Value);

	while (1)
	{
		int Difference = Current->Data.compare(Value);

		if(Difference == 0) {
			Current->Data;
			std::cout << "Value already exists" << '\n';
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
		std::cout << "GetNode(nullptr, \"" << Key << "\"): 'nullptr' Root" << '\n';
		return nullptr;
	}

	Tree* Current = *Root;

	while(Current != nullptr)
	{
		int Difference = Current->Data.compare(Key);

		if(Difference == 0) {
			return Current;

		} else if(Difference > 0) { 
			Current = Current->Right;

		} else {
			Current = Current->Left;

		}
	}

	if(Current == nullptr)
		std::cout << "Value not found" << '\n';

	return Current;
}

void RemoveNode(Tree** Root, const std::string& Key)
{
	if(Root == nullptr) 
	{
		std::cout << "GetNode(nullptr, \"" << Key << "\"): 'nullptr' Root" << '\n';
		return;
	}

	if(GetNode(Root, Key) == nullptr)
	{
		std::cout << "RemoveNode(Root, \"" << Key << "\"): 'Value' not found" << '\n';
		return;
	}

	// Search for the Value
	// Case 1: Value doesn't exist
	// Case 2: Value is found
	// Case 3: The value is on the left (< 0)
	// Case 4: The value is on the right (> 0)

	Tree* Current = *Root;
	Tree* Previous = nullptr;

	while(Current != nullptr)
	{
		int Difference = Current->Data.compare(Key);

		if(Difference == 0) {
			break;

		} else if(Difference > 0) {
			if(Current->Right == nullptr) break;
			Previous = Current;
			Current = Current->Right;

		} else {
			if(Current->Left == nullptr) break;
			Previous = Current;
			Current = Current->Left;

		}
	}

	switch(NumberOfDecendants(Current))
	{
	// Delete a leaf
	case 0:
		if(Previous->Left == Current)
		{
			Previous->Left = nullptr;
			delete Current;
			break;
		}

		Previous->Right = nullptr;
		delete Current;
		break;
		
	default:
		return;
	}
}

void PrintTree(Tree** Root)
{
	Tree* Current = *Root;

	if(Current == nullptr)
	{
		return;
	}

	PrintTree(&Current->Left);
	std::cout << Current->Data << '\n';
	PrintTree(&Current->Right);
}

size_t NumberOfDecendants(Tree * Node)
{
	size_t Num = 0;
	if(Node->Right != nullptr) Num++;
	if(Node->Left != nullptr) Num++;
 
	return Num;
}