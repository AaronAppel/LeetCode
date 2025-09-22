
#include <assert.h>
#include <iostream>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/search-insert-position/

// Complexity O(n), Memory O(1)
// Submitted 21/09/25 3:41pm
// Runtime of 0ms (100%), with RAM usage of 15.53MB (76.7%)
int SearchInsert_v1(const std::vector<int>& nums, int target)
{
	// #NOTE Naive or 1st working solution.

	if (nums.size() > 0)
	{
		int numsRange = nums.size() / 2;
		int index = numsRange;

		const int loopRange = std::sqrt(nums.size()) + 1;
		for (size_t i = 0; i < loopRange; i++)
		{
			if (index < 0)
			{
				index = 0;
			}
			else if (index >= nums.size())
			{
				index = nums.size() - 1;
			}

			if (target == nums[index])
			{
				return index;
			}
			else if (target < nums[index])
			{
				numsRange /= 2;

				if (0 == numsRange)
				{
					index -= 1;
				}
				else
				{
					index -= numsRange;
				}
			}
			else // Greater than
			{
				numsRange /= 2;

				if (0 == numsRange)
				{
					index += 1;
				}
				else
				{
					index += numsRange;
				}
			}
		}

		if (index < 0)
		{
			index = 0;
		}
		else if (index >= nums.size())
		{
			index = nums.size() - 1;
		}

		if (target <= nums[index])
		{
			return index;
		}
		else
		{
			return index + 1;
		}
	}
	return -1;
}

int SearchInsert_v2(const std::vector<int>& nums, int target)
{
	// #NOTE Early returns checking target value against list bound (start and end) values.

	if (!nums.empty())
	{
		if (target <= nums[0])
		{
			return 0;
		}
		else if (target > nums[nums.size() - 1])
		{
			return nums.size();
		}

		int numsRange = nums.size() / 2;
		int index = numsRange;

		const int loopRange = std::sqrt(nums.size()) + 1;
		for (size_t i = 0; i < loopRange; i++)
		{
			if (index < 0)
			{
				index = 0;
			}
			else if (index >= nums.size())
			{
				index = nums.size() - 1;
			}

			if (target == nums[index])
			{
				return index;
			}
			else if (target < nums[index])
			{
				numsRange /= 2;

				if (0 == numsRange)
				{
					index -= 1;
				}
				else
				{
					index -= numsRange;
				}
			}
			else // Greater than
			{
				numsRange /= 2;

				if (0 == numsRange)
				{
					index += 1;
				}
				else
				{
					index += numsRange;
				}
			}
		}

		if (index < 0)
		{
			index = 0;
		}
		else if (index >= nums.size())
		{
			index = nums.size() - 1;
		}

		if (target <= nums[index])
		{
			return index;
		}
		else
		{
			return index + 1;
		}
	}
	return 0;
}

int SearchInsert_v3(const std::vector<int>& nums, int target)
{
	// #NOTE 2 pointer, sliding window solution from comments:

	int low = 0;
	int high = nums.size();
	int mid;

	if (target > nums[high - 1]) {
		return high;
	}

	while (low <= high) {
		mid = (low + high) / 2;

		if (nums[mid] == target) {
			return mid;
		}

		if (target < nums[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}
	return low;
}

#include "Helpers.h"
#include "Testing.h"

typedef int(*SolutionFuncPtr)(const std::vector<int>&, int);

void main_SearchInsertPosition()
{
	SolutionFuncPtr solutionFunc = SearchInsert_v1;

	// LeetCode cases
	const std::vector<int> nums = { 1, 3, 5, 6 };
	assert(solutionFunc(nums, 5) == 2);
	assert(solutionFunc(nums, 2) == 1);
	assert(solutionFunc(nums, 7) == 4);
	assert(solutionFunc(nums, 0) == 0);

	const std::vector<int> nums2 = { 1, 3 };
	assert(solutionFunc(nums2, 1) == 0);

	const std::vector<int> nums3 = { 1, 5, 6, 8, 9, 10 };
	assert(solutionFunc(nums3, 1) == 0);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		SearchInsert_v1,
		SearchInsert_v2,
		SearchInsert_v3,
	};

	RunSolutions(funcs, 2, std::vector<int>{ 1, 3, 5, 6 }, 5);

	int bp = 0;
}

int main() { main_SearchInsertPosition(); };
