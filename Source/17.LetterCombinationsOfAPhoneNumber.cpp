
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problemset/

int LetterCombinationsOfAPhoneNumber_v1(const std::vector<int>& nums, int target) {
	return 0;
}

#include "Testing.h"
typedef int(*SolutionFuncPtr)(const std::vector<int>&, int);

void main_LetterCombinationsOfAPhoneNumber()
{
	SolutionFuncPtr solutionFunc = LetterCombinationsOfAPhoneNumber_v1;

	// LeetCode cases
	std::vector<int> input = { };
	assert(solutionFunc(input, 0) == 0);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		LetterCombinationsOfAPhoneNumber_v1,
	};

	RunSolutions(funcs, "", input, 0);

	int bp = 0;
}

// int main() { main_LetterCombinationsOfAPhoneNumber(); }
