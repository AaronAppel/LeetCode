
#include <assert.h>
#include <cmath>
#include <string>
#include <vector>

// #include "Helpers.h"

// Link to leetcode problem https://leetcode.com/problems/palindrome-number/description/

// Submission 20/03/25 4:45pm
// Leetcode performance is broken
bool PalindromeNumber_v1(int x)
{
	const std::string xStr = std::to_string(x);

	const char* left = &xStr[0];
	const char* right = &xStr[xStr.size() - 1];

	for (size_t i = 0; i < xStr.size() / 2; i++)
	{
		if (*left != *right)
		{
			return false;
		}
		++left;
		--right;
	}

	return true;
}

bool PalindromeNumber_v2(int x)
{
	// DIFF: No string

	if (x < 0) // #NOTE Could also add (|| x != 0 && x % 10 == 0)
	{
		return false;
	}

	int numDigits = 0;
	int xCopy = x;

	while (xCopy)
	{
		++numDigits;
		xCopy /= 10;
	}

	int left = pow(10, numDigits - 1);

	for (size_t i = 0; i < numDigits / 2; i++)
	{
		int l = x / left;
		int r = x % 10;

		if (l != r)
		{
			return false;
		}

		x = x % left;
		x = x / 10;

		left /= 100;
	}

	return true;
}

typedef bool(*SolutionFuncPtr)(int);

void main_PalindromeNumber()
{
	SolutionFuncPtr solutionFunc = PalindromeNumber_v2;

	assert(solutionFunc(121) == true);
	assert(solutionFunc(-121) == false);
	assert(solutionFunc(10) == false);
	assert(solutionFunc(1000021) == false);
	assert(solutionFunc(1001) == true);
	assert(solutionFunc(9999) == true);

	// My cases
	assert(solutionFunc(22) == true);
	assert(solutionFunc(23) == false);
}