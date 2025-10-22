
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* RemoveNthFromEnd_v1(const ListNode* head, int n) {
	return nullptr;
}

#include "Testing.h"
typedef ListNode*(*SolutionFuncPtr)(const ListNode*, int);

void main_RemoveNthFromEnd()
{
	SolutionFuncPtr solutionFunc = RemoveNthFromEnd_v1;

	// LeetCode cases
	assert(solutionFunc(nullptr, 0) == nullptr);

	// My cases
	// assert(solutionFunc() == true);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		RemoveNthFromEnd_v1,
	};

	RunSolutions(funcs, nullptr, nullptr, 0);

	int bp = 0;
}

// int main() { main_RemoveNthFromEnd(); }
