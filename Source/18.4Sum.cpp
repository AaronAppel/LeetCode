
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/4sum/

std::vector<std::vector<int>> fourSum_v1(const std::vector<int>& nums, int target) {
	return { };
}

#include "Testing.h"
typedef std::vector<std::vector<int>>(*SolutionFuncPtr)(const std::vector<int>&, int);

void main_fourSum()
{
	SolutionFuncPtr solutionFunc = fourSum_v1;

	// LeetCode cases
	std::vector<int> input = { };
	std::vector<std::vector<int>> output = { };
	assert(solutionFunc(input, 0) == output);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		fourSum_v1,
	};

	RunSolutions(funcs, output, input, 0);

	int bp = 0;
}

// int main() { main_fourSum(); }
