
#include <assert.h>
#include <vector>

// https: Link to leetcode problem

bool NewProblem_v1()
{
	return false;
}

#include "Testing.h"

typedef bool(*SolutionFuncPtr)();

void main_NewProblem()
{
	SolutionFuncPtr solutionFunc = NewProblem_v1;

	// LeetCode cases
	assert(solutionFunc() == true);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
	};

	// RunSolutions(funcs, output, input);
	// int bp = 0;
}

// int main() { main_NewProblem(); }
