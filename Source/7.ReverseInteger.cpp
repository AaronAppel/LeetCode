
#include <assert.h>
#include <cmath>

#include "Helpers.h"

// Link to leetcode problem https://leetcode.com/problems/reverse-integer/description/

typedef int(*SolutionFuncPtr)(int);

// Submitted 20/03/25
// LeetCode performance metrics are broken
int ReverseInteger_v1(int x)
{
	// #NOTE Unable to use 64-bit values

	if (x == 0)
	{
		return 0;
	}

	constexpr int base = 10;
	int numDigits = 0;
	{
		if (x == 0)
		{
			numDigits = 1;
		}
		else
		{
			int value = x;
			while (value != 0)
			{
				value /= base;
				++numDigits;
			}
		}
	}

	char* arr = new char[numDigits];
	int xCopy = x;
	for (size_t i = 0; i < numDigits; i++)
	{
		int po = powf(base, numDigits - i - 1);
		arr[i] = xCopy / po;
		xCopy -= arr[i] * po;
	}

	x = 0;
	for (size_t i = 0; i < numDigits; i++)
	{
		int toAdd = arr[i] * pow(base, i);

		if ((x > 0 && x + toAdd < x) ||
			((x < 0 && x + toAdd > x)))
		{
			return 0;
		}
		x += toAdd;
	}

	// #TODO Bounds check

	delete[] arr;

	return x;
}

// Submitted 20/03/25
// LeetCode performance metrics are broken
int32_t ReverseInteger_v2(int32_t x)
{
	int32_t returnValue = 0;

	while (x != 0)
	{
		int32_t y = x % 10;

		// #NOTE Excluding check of last digit value as the input is guaranteed to be a valid 32 bit value
		if (returnValue > INT32_MAX / 10 ||
			returnValue < INT32_MIN / 10)
		{
			return 0;
		}

		returnValue *= 10;
		returnValue += y;
		x /= 10;
	}

	return returnValue;
}

void main_ReverseInteger()
{
	SolutionFuncPtr solutionFunc = ReverseInteger_v2;

	// LeetCode cases
	assert(solutionFunc(123) == 321);
	assert(solutionFunc(-123) == -321);
	assert(solutionFunc(120) == 21);
	assert(solutionFunc(1534236469) == 0);
	assert(solutionFunc(-2147483648) == 0);

	// My cases
	assert(solutionFunc(-13) == -31);
	assert(solutionFunc(INT32_MAX) == 0);
	assert(solutionFunc(-1534236469) == 0);
}
