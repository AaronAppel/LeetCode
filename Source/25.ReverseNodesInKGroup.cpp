
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

ListNode* ReverseNodesInKGroup_v1(ListNode* lists, int k)
{
	return nullptr;
}

#include "Testing.h"
typedef ListNode*(*SolutionFuncPtr)(ListNode*, int);

void main_ReverseNodesInKGroup()
{
	SolutionFuncPtr solutionFunc = ReverseNodesInKGroup_v1;

	// LeetCode cases
	assert(solutionFunc(nullptr, 0) == nullptr);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		ReverseNodesInKGroup_v1,
	};

	RunSolutions(funcs, nullptr, nullptr, 0);

	int bp = 0;
}

// int main() { main_ReverseNodesInKGroup(); }
