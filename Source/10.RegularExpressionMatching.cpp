
#include <assert.h>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/regular-expression-matching/

// ???
bool RegularExpressionMatching_v1(std::string s, std::string p) {
	return false;
}

#include "Testing.h"

typedef bool(*SolutionFuncPtr)(const std::string, const std::string);

void main_RegularExpressionMatching()
{
	SolutionFuncPtr solutionFunc = RegularExpressionMatching_v1;

	// LeetCode cases
	std::vector<std::string> input = { "", "" };
	assert(solutionFunc(input[0], input[1]) == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		RegularExpressionMatching_v1,
	};

	RunSolutions(funcs, true, input[0], input[1]);

	int bp = 0;
}

int main() { main_RegularExpressionMatching(); }
