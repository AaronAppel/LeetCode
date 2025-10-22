
#include <assert.h>
#include <string>
#include <vector>

// https://leetcode.com/problems/valid-parentheses/

bool ValidParentheses_v1(const std::string& s) {
	return false;
}

#include "Testing.h"
typedef bool(*SolutionFuncPtr)(const std::string&);

void main_ValidParentheses()
{
	SolutionFuncPtr solutionFunc = ValidParentheses_v1;

	// LeetCode cases
	assert(solutionFunc("") == true);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		ValidParentheses_v1,
	};

	RunSolutions(funcs, true, "");

	int bp = 0;
}

// int main() { main_ValidParentheses(); }
