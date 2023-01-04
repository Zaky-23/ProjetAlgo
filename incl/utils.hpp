#pragma once

#include <algorithm>
#include <string>
#include <set>
#include <vector>

#include "../incl/tree.hpp"

std::set<size_t> FindIntersections(Tree** Root, const std::string& Key1, const std::string& Key2);
std::set<size_t> FindPosOccurences(const std::vector<std::string>& Phrases, const std::string& Word);
bool FindPhrase(const std::string& Phrase, const std::vector<std::string>& Phrases);
