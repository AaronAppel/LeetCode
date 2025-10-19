
#include <assert.h>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problemset/

std::string LongestCommonPrefix_v1(const std::vector<std::string>& strings)
{
	return "";
}

#include "Testing.h"

typedef std::string(*SolutionFuncPtr)(const std::vector<std::string>&);

void main_LongestCommonPrefix()
{
	SolutionFuncPtr solutionFunc = LongestCommonPrefix_v1;

	// LeetCode cases
	std::vector<std::string> input = { "", "" };
	assert(solutionFunc(input) == "");

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		LongestCommonPrefix_v1,
	};

	RunSolutions(funcs, "", input);

	int bp = 0;
}

// int main() { main_LongestCommonPrefix(); }
