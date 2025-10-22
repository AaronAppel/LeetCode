
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

ListNode* MergeKSortedLists_v1(std::vector<ListNode*>& lists)
{
	return nullptr;
}

#include "Testing.h"
typedef ListNode*(*SolutionFuncPtr)(std::vector<ListNode*>&);

void main_MergeKSortedLists()
{
	SolutionFuncPtr solutionFunc = MergeKSortedLists_v1;

	// LeetCode cases
	std::vector<ListNode*> input = { nullptr };
	assert(solutionFunc(input) == nullptr);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		MergeKSortedLists_v1,
	};

	RunSolutions(funcs, nullptr, input);

	int bp = 0;
}

// int main() { main_MergeKSortedLists(); }
