
#include <assert.h>
#include <string>
#include <vector>

// https://leetcode.com/problems/generate-parentheses/description/

std::vector<std::string> GenerateParenthesis_v1(int n)
{
	return { };
}

#include "Testing.h"
typedef std::vector<std::string>(*SolutionFuncPtr)(int);

void main_GenerateParenthesis()
{
	SolutionFuncPtr solutionFunc = GenerateParenthesis_v1;

	// LeetCode cases
	std::vector<std::string> output;
	assert(solutionFunc(0) == output);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		GenerateParenthesis_v1,
	};

	RunSolutions(funcs, output, 0);

	int bp = 0;
}

// int main() { main_GenerateParenthesis(); }
