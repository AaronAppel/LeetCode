
#include <assert.h>
#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int RemoveDuplicatesFromSortedArray_v1(std::vector<int>& nums)
{
	return 0;
}

#include "Testing.h"

typedef int(*SolutionFuncPtr)(std::vector<int>&);

void main_RemoveDuplicatesFromSortedArray()
{
	SolutionFuncPtr solutionFunc = RemoveDuplicatesFromSortedArray_v1;

	// LeetCode cases
	std::vector<int> input = {};
	assert(solutionFunc(input) == 0);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		RemoveDuplicatesFromSortedArray_v1
	};

	// RunSolutions(funcs, output, input);
	// int bp = 0;
}

// int main() { main_RemoveDuplicatesFromSortedArray(); }
