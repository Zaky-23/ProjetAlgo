#pragma once

#include <iostream>
#include <set>
#include <string>
#include <vector>

typedef struct Tree {
	Tree* Right;
	Tree* Left;
	std::string Key;
	std::set<size_t> Occurences;
}Tree;

Tree* CreateNode(const std::string& Value);
void InsertNode(Tree** Root, const std::string& Value, const std::set<size_t>& WordOccurences);
Tree* GetNode(Tree** Root, const std::string& Key);
void PrintTree(Tree** Root);