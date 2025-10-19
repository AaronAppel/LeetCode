
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problemset/

int threeSumClosest_v1(const std::vector<int>& nums, int target) {
	return 0;
}

#include "Testing.h"
typedef int(*SolutionFuncPtr)(const std::vector<int>&, int);

void main_3SumClosest()
{
	SolutionFuncPtr solutionFunc = threeSumClosest_v1;

	// LeetCode cases
	std::vector<int> input = { };
	assert(solutionFunc(input, 0) == 0);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		threeSumClosest_v1,
	};

	RunSolutions(funcs, "", input, 0);

	int bp = 0;
}

// int main() { main_3SumClosest(); }
