#pragma once

#include <iostream>
#include <string>

static const std::string NOT_FOUND = "**NotFound**";

typedef struct Tree {
	Tree* Right;
	Tree* Left;
	std::string Data;
}Tree;

Tree* CreateNode(const std::string& Value);
void InsertNode(Tree** Root, const std::string& Value);
Tree* GetNode(Tree** Root, const std::string& Key);
void RemoveNode(Tree** Root, const std::string& Key);
void PrintTree(Tree** Root);
size_t NumberOfDecendants(Tree* Node);
