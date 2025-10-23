
#include <assert.h>
#include <string>
#include <vector>

// https://leetcode.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* SwapNodesInPairs_v1(ListNode* lists)
{
	return nullptr;
}

#include "Testing.h"
typedef ListNode*(*SolutionFuncPtr)(ListNode*);

void main_SwapNodesInPairs()
{
	SolutionFuncPtr solutionFunc = SwapNodesInPairs_v1;

	// LeetCode cases
	assert(solutionFunc(nullptr) == nullptr);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		SwapNodesInPairs_v1,
	};

	RunSolutions(funcs, nullptr, nullptr);

	int bp = 0;
}

// int main() { main_SwapNodesInPairs(); }
