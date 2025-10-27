
#include <assert.h>
#include <vector>

// https://leetcode.com/problems/remove-element/

int RemoveElement_v1(std::vector<int>& nums, int val)
{
	return false;
}

#include "Testing.h"

typedef int(*SolutionFuncPtr)(std::vector<int>&, int);

void main_RemoveElement()
{
	SolutionFuncPtr solutionFunc = RemoveElement_v1;

	// LeetCode cases
	std::vector<int> input = {};
	assert(solutionFunc(input, 0) == 0);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
	};

	// RunSolutions(funcs, output, input);
	// int bp = 0;
}

// int main() { main_RemoveElement(); }
