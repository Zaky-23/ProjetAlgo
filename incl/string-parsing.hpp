#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

const static std::string ERROR_FLAG = "\u001b[31mErrorCode \u001b[31m";

std::string ExtractText(const std::string& Path);
size_t ReplaceTextWith(std::string& Str, const std::string& Pattern, const char With);
std::vector<std::string> SplitString(const std::string& Str, char Pattern);
std::set<std::string> ExtractWordsFromFile(const std::string& Path, const std::string& Patterns);
std::vector<std::string> ExtractPhrasesFromFile(const std::string& Path);
void PrintWords(const std::set<std::string>& Words);
void PrintPhrases(const std::vector<std::string>& Phrases);

