
#include <assert.h>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problemset/

// Complexity O(n), Memory O(1)
// Submitted 20/10/25 10:40pm
// Runtime of 1ms (14.81%), with RAM usage of 11.79MB (85.62%)
std::string LongestCommonPrefix_v1(const std::vector<std::string>& strings)
{
	// #NOTE Naive solution

	if (strings.size() == 0)
		return "";

	std::string longestPrefix = strings[0];

	for (size_t i = 1; i < strings.size(); i++)
	{
		if (longestPrefix.size() > strings[i].size())
		{
			longestPrefix = longestPrefix.substr(0, strings[i].size());
		}

		unsigned int shorterLength = strings[i].size() < longestPrefix.size() ? strings[i].size() : longestPrefix.size();
		for (size_t j = 0; j < shorterLength; j++)
		{
			if (longestPrefix[j] != strings[i][j])
			{
				if (j < longestPrefix.size())
				{
					longestPrefix = longestPrefix.substr(0, j);
				}
				break;
			}
		}

		if (longestPrefix.size() == 0)
		{
			return "";
		}
	}

	return longestPrefix;
}

#include "Testing.h"

typedef std::string(*SolutionFuncPtr)(const std::vector<std::string>&);

void main_LongestCommonPrefix()
{
	SolutionFuncPtr solutionFunc = LongestCommonPrefix_v1;

	// LeetCode cases
	std::vector<std::string> input = { "", "" };
	assert(solutionFunc(input) == "");

	// #NOTE All string entries must start with same prefix
	input = { "ab", "a" };
	assert(solutionFunc(input) == "a");

	input = { "flower", "flow", "flight" };
	assert(solutionFunc(input) == "fl");

	input = { "dog", "racecar", "car" };
	assert(solutionFunc(input) == "");

	input = { "a" };
	assert(solutionFunc(input) == "a");

	// My cases
	input = { "flower", "flow", "flight", "fli" };
	assert(solutionFunc(input) == "fl");

	input = { "abcdefghijklmno", "abcdefghijklmnopqrstuvwxyz" };
	assert(solutionFunc(input) == "abcdefghijklmno");

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		LongestCommonPrefix_v1,
	};

	// RunSolutions(funcs, "fl", input);
}

// int main() { main_LongestCommonPrefix(); }
