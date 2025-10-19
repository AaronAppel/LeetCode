
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problemset/

std::vector<std::vector<int>> threeSum_v1(const std::vector<int>& nums)
{
	return { };
}

#include "Testing.h"
typedef std::vector<std::vector<int>>(*SolutionFuncPtr)(const std::vector<int>&);

void main_3Sum()
{
	SolutionFuncPtr solutionFunc = threeSum_v1;

	// LeetCode cases
	std::vector<int> input = { };
	std::vector<int> output = { };
	assert(solutionFunc(input)[0] == output);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		threeSum_v1,
	};

	RunSolutions(funcs, "", input);

	int bp = 0;
}

// int main() { main_3Sum(); }