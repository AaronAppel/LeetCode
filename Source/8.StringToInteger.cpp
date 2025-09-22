
#include <assert.h>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/string-to-integer-atoi/

// Complexity O(n), Memory O(1)
// Submitted 30/03/25 3:19pm
// Runtime of 3ms (15.23%), with RAM usage of 9MB (97.41%)
int StringToInteger_v1(std::string s)
{
	// NAIVE Lots of if checks, duplicated logic, and an enum state

	enum State
	{
		Unset = 0,
		Positive,
		Negative
	};

	int returnValue = 0;

	if (s.empty())
	{
		return returnValue;
	}

	int startingIndex = 0;
	bool foundWhitespace = false;
	State numberState = Unset;

	for (; startingIndex < s.size(); startingIndex++)
	{
		if (s[startingIndex] >= '0' && s[startingIndex] <= '9')
		{
			break;
		}
		else if (s[startingIndex] == '-')
		{
			if (numberState != Unset)
			{
				return returnValue;
			}
			numberState = Negative;
		}
		else if (s[startingIndex] == '+')
		{
			if (numberState != Unset)
			{
				return returnValue;
			}
			numberState = Positive;
		}
		else if (s[startingIndex] == ' ')
		{
			if (foundWhitespace && s[startingIndex -1] != ' ')
			{
				return returnValue;
			}
			foundWhitespace = true;
		}
		else
		{
			return returnValue; // #NOTE Invalid character encountered
		}
	}

	// Sum characters
	for (size_t i = startingIndex; i < s.size(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			break;
		}

		if (numberState == Negative)
		{
			if (returnValue <= INT32_MIN / 10)
			{
				if (i + 1 < s.size() &&
					s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					return INT32_MIN;
				}

				if ((s[startingIndex] - '0') * -1 < INT32_MIN / 1000000000)
				{
					return INT32_MIN;
				}

				const int diff = returnValue - (INT32_MIN / 10);
				if (diff >= 0 && diff <= 8 &&
					(s[i] - '0') * -1 >= INT32_MIN % 10)
				{
					returnValue *= 10;
					returnValue -= s[i] - '0';
					return returnValue;
				}

				return INT32_MIN;
			}
		}
		else
		{
			if (returnValue >= INT32_MAX / 10)
			{
				if (i + 1 < s.size() &&
					s[i+1] >= '0' && s[i+1] <= '9')
				{
					return INT32_MAX;
				}

				if (s[startingIndex] - '0' > INT32_MAX / 1000000000)
				{
					return INT32_MAX;
				}

				const int diff = returnValue - (INT32_MAX / 10);
				if (diff <= 7 &&
					s[i] - '0' <= INT32_MAX % 10)
				{
					returnValue *= 10;
					returnValue += s[i] - '0';
					return returnValue;
				}

				return INT32_MAX;
			}
		}

		returnValue *= 10;
		if (numberState == Negative)
		{
			returnValue -= s[i] - '0';
		}
		else
		{
			returnValue += s[i] - '0';
		}
	}

	return returnValue;
}

int StringToInteger_v2(std::string s)
{
	// DIFF Refactored v1

	enum State : unsigned char
	{
		Positive = 0,
		Negative,
		Unset
	};

	constexpr int errorReturn = 0;

	if (s.empty())
	{
		return errorReturn;
	}

	bool foundWhitespace = false;
	State numberState = Unset;

	int startingIndex = 0;
	for (; startingIndex < s.size(); startingIndex++)
	{
		if (s[startingIndex] >= '0' && s[startingIndex] <= '9')
		{
			break; // #NOTE No further characters should be considered
		}
		else if (s[startingIndex] == '-' || s[startingIndex] == '+')
		{
			if (numberState != Unset)
			{
				return errorReturn; // #NOTE Number state changed more than once
			}
			numberState = static_cast<State>(s[startingIndex] == '-');
		}
		else if (s[startingIndex] == ' ')
		{
			if (foundWhitespace && s[startingIndex - 1] != ' ')
			{
				return errorReturn; // #NOTE Whitespace re-encountered after break
			}
			foundWhitespace = true;
		}
		else
		{
			return errorReturn; // #NOTE Invalid character encountered
		}
	}

	// Sum characters
	int returnValue = 0;
	for (size_t i = startingIndex; i < s.size(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			break;
		}

		if (numberState == Negative)
		{
			if (returnValue <= INT32_MIN / 10)
			{
				if (i + 1 < s.size() &&
					s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					return INT32_MIN;
				}

				if ((s[startingIndex] - '0') * -1 < INT32_MIN / 1000000000)
				{
					return INT32_MIN;
				}

				const int diff = returnValue - (INT32_MIN / 10);
				if (diff >= 0 && diff <= 8 &&
					(s[i] - '0') * -1 >= INT32_MIN % 10)
				{
					returnValue *= 10;
					returnValue -= s[i] - '0';
					return returnValue;
				}

				return INT32_MIN;
			}
		}
		else
		{
			if (returnValue >= INT32_MAX / 10)
			{
				if (i + 1 < s.size() &&
					s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					return INT32_MAX;
				}

				if (s[startingIndex] - '0' > INT32_MAX / 1000000000)
				{
					return INT32_MAX;
				}

				const int diff = returnValue - (INT32_MAX / 10);
				if (diff <= 7 &&
					s[i] - '0' <= INT32_MAX % 10)
				{
					returnValue *= 10;
					returnValue += s[i] - '0';
					return returnValue;
				}

				return INT32_MAX;
			}
		}

		returnValue *= 10;
		if (numberState == Negative)
		{
			returnValue -= s[i] - '0';
		}
		else
		{
			returnValue += s[i] - '0';
		}
	}

	return returnValue;
}

// Complexity O(n), Memory O(1)
// Submitted 30/03/25 7:43pm
// Runtime of 0ms (100%), with RAM usage of 9.12MB (57.55%)
int StringToInteger_v3(std::string s)
{
	int signMultiplier = 1;
	int currentIndex = 0;

	while (currentIndex < s.size() && s[currentIndex] == ' ')
	{
		++currentIndex;
	}

	if (s[currentIndex] == '-')
	{
		signMultiplier = -1;
		++currentIndex;
	}
	else if (s[currentIndex] == '+')
	{
		++currentIndex;
	}

	int returnValue = 0;
	while (currentIndex < s.size() &&
		s[currentIndex] >= '0' && s[currentIndex] <= '9')
	{
		const int digit = s[currentIndex] - '0';

		if (returnValue > (INT_MAX - digit) / 10)
		{
			if (signMultiplier == 1)
			{
				return INT32_MAX;
			}
			else
			{
				return INT32_MIN;
			}
		}
		returnValue = returnValue * 10 + digit;

		++currentIndex;
	}

	return returnValue * signMultiplier;
}

#include "Testing.h"

typedef int(*SolutionFuncPtr)(std::string);

void main_StringToInteger()
{
	SolutionFuncPtr solutionFunc = StringToInteger_v3;

	// LeetCode cases
	assert(solutionFunc("42") == 42);
	assert(solutionFunc(" -42") == -42);
	assert(solutionFunc("1337c0d3") == 1337);
	assert(solutionFunc("-91283472332") == INT32_MIN);
	assert(solutionFunc("   -042") == -42);
	assert(solutionFunc("+1") == 1);
	assert(solutionFunc("+-12") == 0);
	assert(solutionFunc("2147483646") == 2147483646);
	assert(solutionFunc("21474836460") == INT32_MAX);
	assert(solutionFunc("-2147483647") == -2147483647);
	assert(solutionFunc("-2147483649") == INT32_MIN);
	assert(solutionFunc("2147483800") == INT32_MAX);
	assert(solutionFunc("  +  413") == 0);
	assert(solutionFunc("      -11919730356x") == INT32_MIN);

	// My cases
	assert(solutionFunc("ABC") == 0);
	assert(solutionFunc("-2147483648") == INT32_MIN);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		StringToInteger_v1,
		StringToInteger_v2,
		StringToInteger_v3
	};

	RunSolutions(funcs, INT32_MAX, std::string("2147483800"));

	int bp = 0;
}

// int main() { main_StringToInteger(); }
