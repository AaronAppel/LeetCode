
#include <assert.h>

// Link to leetcode problem https://leetcode.com/problemset/

bool NewProblem_v1()
{
	return false;
}

#include "Helpers.h"
#include "Testing.h"

typedef bool(*SolutionFuncPtr)();

void main_NewProblem()
{
	SolutionFuncPtr solutionFunc = NewProblem_v1;
	assert(solutionFunc() == true);
}

// int main() { main_NewProblem(); }
