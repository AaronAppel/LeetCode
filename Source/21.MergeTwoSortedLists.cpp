
#include <assert.h>
#include <vector>

// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* MergeTwoSortedLists_v1(const ListNode* list1, const ListNode* list2)
{
	return nullptr;
}

#include "Testing.h"
typedef ListNode*(*SolutionFuncPtr)(const ListNode*, const ListNode*);

void main_MergeTwoSortedLists()
{
	SolutionFuncPtr solutionFunc = MergeTwoSortedLists_v1;

	// LeetCode cases
	assert(solutionFunc(nullptr, nullptr) == nullptr);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		MergeTwoSortedLists_v1,
	};

	RunSolutions(funcs, nullptr, nullptr, nullptr);

	int bp = 0;
}

// int main() { main_MergeTwoSortedLists(); }
