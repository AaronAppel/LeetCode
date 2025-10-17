
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/container-with-most-water/

// Complexity O(n^2), Memory O(1)
// Submitted 16/10/25 7:19pm
// Runtime of DNF (0%), with RAM usage of unknown (0.%)
int ContainerWithMostWater_v1(const std::vector<int>& height)
{
	// #NOTE Naive solution using O(n^2) complexity

	unsigned int greatestVolume = 0;

	for (size_t i = 0; i < height.size() - 1; i++)
	{
		for (size_t j = i + 1; j < height.size(); j++)
		{
			const unsigned int shorterLineHeight = height[i] < height[j] ? height[i] : height[j];
			const unsigned int currentVolume = shorterLineHeight * (j - i);

			if (currentVolume > greatestVolume)
			{
				greatestVolume = currentVolume;
			}
		}
	}

	return greatestVolume;
}

// Complexity O(n^2), Memory O(1)
// Submitted 16/10/25 7:25pm
// Runtime of DNF (0%), with RAM usage of unknown (0.%)
int ContainerWithMostWater_v2(const std::vector<int>& height)
{
	// #NOTE Naive solution, plus early return

	unsigned int greatestVolume = 0;

	for (size_t i = 0; i < height.size() - 1; i++)
	{
		if (greatestVolume > height[i] * height.size() - i)
		{
			continue;
		}

		for (size_t j = i + 1; j < height.size(); j++)
		{
			const unsigned int shorterLineHeight = height[i] < height[j] ? height[i] : height[j];
			const unsigned int currentVolume = shorterLineHeight * (j - i);

			if (currentVolume > greatestVolume)
			{
				greatestVolume = currentVolume;
			}
		}
	}

	return greatestVolume;
}

// Complexity O(n^2), Memory O(1)
// Submitted 16/10/25 7:43pm
// Runtime of 3ms (35.85%), with RAM usage of 62.96MB (48.1%)
int ContainerWithMostWater_v3(const std::vector<int>& height)
{
	// #NOTE 2 pointers approach

	unsigned int greatestVolume = 0;

	unsigned lowerIndex = 0;
	unsigned upperIndex = height.size() - 1;

	while (lowerIndex < upperIndex)
	{
		const unsigned int shorterLineHeight = height[lowerIndex] < height[upperIndex] ? height[lowerIndex] : height[upperIndex];
		const unsigned int distanceBetweenLines = upperIndex - lowerIndex;
		const unsigned int currentVolume = shorterLineHeight * distanceBetweenLines;

		if (currentVolume > greatestVolume)
		{
			greatestVolume = currentVolume;
		}

		if (height[lowerIndex] < height[upperIndex])
		{
			++lowerIndex;
		}
		else
		{
			--upperIndex;
		}
	}

	return greatestVolume;
}

#include "Testing.h"

typedef int(*SolutionFuncPtr)(const std::vector<int>&);

void main_ContainerWithMostWater()
{
	SolutionFuncPtr solutionFunc = ContainerWithMostWater_v3;

	// LeetCode cases
	std::vector<int> input = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	assert(solutionFunc(input) == 49);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		ContainerWithMostWater_v1,
		ContainerWithMostWater_v2,
		ContainerWithMostWater_v3,
	};

	RunSolutions(funcs, 49, input);

	int bp = 0;
}

int main() { main_ContainerWithMostWater(); }
