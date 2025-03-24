
#include <assert.h>
#include <unordered_map>
#include <string>

#include "Helpers.h"

// Link to leetcode problem https://leetcode.com/problems/integer-to-roman/

// Complexity O(n), Memory O(1)
// Submitted 22/03/25 5:21pm
// Runtime of 16ms (7.15%), with RAM usage of 13.30MB (46.12%)
int RomanToInteger_v1(const std::string& s)
{
	// NAIVE

	int finalSum = 0;

	std::unordered_map<char, int> charToInts =
	{
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 }
	};

	int runningSum = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		const bool rightValueInRange = i < s.size() - 1;
		if (rightValueInRange)
		{
			const bool nextValueIsGreater = charToInts[s[i]] < charToInts[s[i + 1]];
			if (nextValueIsGreater)
			{
				runningSum -= charToInts[s[i]];
			}
			else
			{
				runningSum += charToInts[s[i]];
				finalSum += runningSum;
				runningSum = 0;
			}
		}
		else
		{
			runningSum += charToInts[s[i]];
			finalSum += runningSum;
			runningSum = 0;
		}
	}

	return finalSum;
}

// Complexity O(n), Memory O(1)
// Submitted 22/03/25 5:25pm
// Runtime of 11ms (25.03%), with RAM usage of 13.24MB (46.12%)
int RomanToInteger_v2(const std::string& s)
{
	// DIFF Remove runningSum

	int finalSum = 0;

	std::unordered_map<char, int> charToInts =
	{
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 }
	};

	for (size_t i = 0; i < s.size(); i++)
	{
		const bool rightValueInRange = i < s.size() - 1;
		if (rightValueInRange)
		{
			const bool nextValueIsGreater = charToInts[s[i]] < charToInts[s[i + 1]];
			if (nextValueIsGreater)
			{
				finalSum -= charToInts[s[i]];
			}
			else
			{
				finalSum += charToInts[s[i]];
			}
		}
		else
		{
			finalSum += charToInts[s[i]];
		}
	}

	return finalSum;
}

// Complexity O(n), Memory O(1)
// Submitted 22/03/25 5:40pm
// Runtime of ms (25.03%), with RAM usage of ~10MB (~93%)
int RomanToInteger_v3(const std::string& s)
{
	// DIFF Switch statement instead of map

	int finalSum = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		const bool rightValueInRange = i + 1 < s.size();

		switch (s[i])
		{
		case 'I':
			if (rightValueInRange &&
				(s[i + 1] == 'V' ||
				 s[i + 1] == 'X'))
			{
				finalSum -= 1;
			}
			else
			{
				finalSum += 1;
			}
			break;
		case 'V':
			if (rightValueInRange && s[i + 1] == 'X')
			{
				finalSum -= 5;
			}
			else
			{
				finalSum += 5;
			}
			break;
		case 'X':
			if (rightValueInRange &&
				(s[i + 1] == 'L' ||
				 s[i + 1] == 'C'))
			{
				finalSum -= 10;
			}
			else
			{
				finalSum += 10;
			}
			break;
		case 'L':
			if (rightValueInRange && s[i + 1] == 'C')
			{
				finalSum -= 50;
			}
			else
			{
				finalSum += 50;
			}
			break;
		case 'C':
			if (rightValueInRange &&
				(s[i + 1] == 'D' ||
				 s[i + 1] == 'M'))
			{
				finalSum -= 100;
			}
			else
			{
				finalSum += 100;
			}
			break;
		case 'D':
			if (rightValueInRange && s[i + 1] == 'M')
			{
				finalSum -= 500;
			}
			else
			{
				finalSum += 500;
			}
			break;
		case 'M':
			finalSum += 1000;
			break;
		}
	}

	return finalSum;
}

// Complexity O(n), Memory O(1)
// Submitted 22/03/25 6:13pm
// Runtime of 0ms? (100%)?, with RAM usage of ~10MB (~93%)
int RomanToInteger_v4(const std::string& s)
{
	// DIFF Evaluate and increment 2 characters at a time instead of subtracting

	int finalSum = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		const bool rightValueInRange = i + 1 < s.size();

		switch (s[i])
		{
		case 'I':
			if (rightValueInRange && s[i + 1] == 'V')
			{
				finalSum += 4;
				++i;
			}
			else if (rightValueInRange && s[i + 1] == 'X')
			{
				finalSum += 9;
				++i;
			}
			else
			{
				finalSum += 1;
			}
			break;
		case 'V':
			if (rightValueInRange && s[i + 1] == 'X')
			{
				finalSum += 5;
				++i;
			}
			else
			{
				finalSum += 5;
			}
			break;
		case 'X':
			if (rightValueInRange && s[i + 1] == 'L')
			{
				finalSum += 40;
				++i;
			}
			else if (rightValueInRange && s[i + 1] == 'C')
			{
				finalSum += 90;
				++i;
			}
			else
			{
				finalSum += 10;
			}
			break;
		case 'L':
			if (rightValueInRange && s[i + 1] == 'C')
			{
				finalSum += 50;
				++i;
			}
			else
			{
				finalSum += 50;
			}
			break;
		case 'C':
			if (rightValueInRange && s[i + 1] == 'D')
			{
				finalSum += 400;
				++i;
			}
			else if (rightValueInRange && s[i + 1] == 'M')
			{
				finalSum += 900;
				++i;
			}
			else
			{
				finalSum += 100;
			}
			break;
		case 'D':
			if (rightValueInRange && s[i + 1] == 'M')
			{
				finalSum += 500;
				++i;
			}
			else
			{
				finalSum += 500;
			}
			break;
		case 'M':
			finalSum += 1000;
			break;
		}
	}

	return finalSum;
}

typedef int(*SolutionFuncPtr)(const std::string&);

void main_RomanToInteger()
{
	 SolutionFuncPtr solutionFunc = RomanToInteger_v4;

	 // LeetCode cases
	 assert(solutionFunc("III") == 3);
	 assert(solutionFunc("LVIII") == 58);
	 assert(solutionFunc("MCMXCIV") == 1994);
	 assert(solutionFunc("IX") == 9);
	 assert(solutionFunc("DCXXI") == 621);

	 const int iterations = 50;
	 double runningSum = 0.;
	 for (size_t i = 0; i < iterations; i++)
	 {
		 double start = NowMs();
		 assert(solutionFunc("MCMXCIV") == 1994);
		 double stop = NowMs();

		 runningSum += stop - start;
	 }

	 double averageDurationMs = runningSum / iterations;
	 int bp = 0;
}

// int main() { main_RomanToInteger(); };
