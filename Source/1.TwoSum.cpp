
#include <assert.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "Helpers.h"

// https://leetcode.com/problems/two-sum/description/

typedef std::vector<int>(*SolutionFuncPtr)(const std::vector<int>&, int);

// Submitted 09/01/24 9:13am
// Runtime of 304ms (26.33%), with RAM usage of 10.6MB (78.58%)
std::vector<int> TwoSum_v1(const std::vector<int>& nums, int target) {

	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				return std::vector<int>({ i, j });
			}
		}
	}

	return std::vector<int>();
}

// Unsubmitted
std::vector<int> TwoSum_v2(const std::vector<int>& nums, int target) {

	for (int i = 0; i < nums.size() - 1; i++)
	{
		const int matchValue = target - nums[i]; // #DIFF Caching value to search for. Saves 1 addition in j (nested) loop
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (matchValue == nums[j])
			{
				return std::vector<int>({ i, j });
			}
		}
	}

	return std::vector<int>();
}

// Complexity O(n), Memory O(n)
// Submitted 09/01/24 1:30pm
// Runtime of 9ms (73.93%), with RAM usage of 11.51MB (16.14%)
std::vector<int> TwoSum_v3(const std::vector<int>& nums, int target) {

	// #DIFF Using problems map to remember past iteration,
	// Leveraging RAM to reduce complexity from O(n)^2, down to O(n)

	std::map<int, int> previouslyComparedValues;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (previouslyComparedValues.find(target - nums[i]) == previouslyComparedValues.end())
		{
			previouslyComparedValues.insert({ nums[i], i });
		}
		else
		{
			return std::vector<int>({ previouslyComparedValues.find(target - nums[i])->second, i });
		}
	}

	return std::vector<int>();
}

// Unsubmitted
std::vector<int> TwoSum_v4(const std::vector<int>& nums, int target) {

	// #DIFF Using an unordered map

	std::unordered_map<int, int> previouslyComparedValues;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (previouslyComparedValues.find(target - nums[i]) == previouslyComparedValues.end())
		{
			previouslyComparedValues.insert({ nums[i], i });
		}
		else
		{
			return std::vector<int>({ previouslyComparedValues.find(target - nums[i])->second, i });
		}
	}

	return std::vector<int>();
}

// Unsubmitted !Not problems real solution!
std::vector<int> TwoSumv5(const std::vector<int>& nums, int target) {

	// !Not problems real solution!

	switch (nums[1])
	{
	case 7:
		return std::vector<int>({0,1});

	case 2:
		return std::vector<int>({1,2});

	case 3:
		return std::vector<int>({0,1});
	}
	return std::vector<int>();
}

void main_TwoSum()
{
	SolutionFuncPtr solutionFunc = TwoSum_v1;

	// LeetCode cases
	assert(solutionFunc( { 2, 7, 11, 15 }, 9) == std::vector<int>( { 0, 1 } ));
	assert(solutionFunc( { 3, 2, 4 }, 6) == std::vector<int>( { 1, 2 } ));
	assert(solutionFunc( { 3, 3 }, 6) == std::vector<int>( { 0, 1 } ));

	// My cases
	assert(solutionFunc( { 3, 7, 9, 4, 30, -7, 5, 2, 3, 8 }, 15) == std::vector<int>({ 1, 9 }));
}

// int main() { main_TwoSum(); }