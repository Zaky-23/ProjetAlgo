#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../incl/tree.hpp"

static const char* FILE_PATH = "input/sample.txt";

int main()
{	
	#pragma region File IO
	// // text a traiter
	// std::string Text;
	// // std::ios::in == read_mode
	// std::ifstream File;
	// // attraper les erreurs
	// File.exceptions(std::ios::failbit | std::ios::badbit);
	// try {
	// 	File.open(FILE_PATH, std::ios::in);

	// 	// buffer chaine de caractere
	// 	std::stringstream StringBuffer;
	// 	StringBuffer << File.rdbuf();

	// 	File.close();

	// 	Text = StringBuffer.str();
	// } catch(std::ifstream::failure error) {
	// 	std::cout << "Error: " << error.what() << '\n';
	// 	return -1;
	// }

	// std::cout << Text << std::endl;
	#pragma endregion

	Tree** Root = nullptr;
	Tree* Node = CreateNode("Hi");
	Root = &Node;

	InsertNode(Root, "Hello");
	InsertNode(Root, "Hellooo");
	InsertNode(Root, "Heo");
	InsertNode(Root, "Hllo");

	RemoveNode(Root, "Hllo");

	PrintTree(Root);

	return 0;
}