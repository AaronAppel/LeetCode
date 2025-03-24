
#include <assert.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector> // For NeetCode's solution

#include "Testing.h"

// Link to leetcode problem https://leetcode.com/problems/integer-to-roman/

// Complexity O(n), Memory O(1)
// Submitted 23/03/25 9:15pm
// Runtime of 0ms? (100%)?, with RAM usage of 8.68MB (90.84%)
std::string IntegerToRoman_v1(int num)
{
	// NAIVE Iterate over all numerals from largest to smallest

	int numCopy = num;
	int numDigits = 0;
	while (numCopy)
	{
		numCopy /= 10;
		++numDigits;
	}

	unsigned short values[] = { 1000, 500, 100, 50, 10, 5, 1 };
	unsigned char chars[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I'};

	std::string returnStr;
	int counter = 0;

	while (num)
	{
		const int power = pow(10, numDigits - counter - 1);
		const int digitValue = num / power;
		const int digitPower = digitValue * power;

		if (digitValue == 1 || digitValue == 5)
		{
			++counter;

			// Check for 2 digit size change
			if (power / 10 > 0)
			{
				const int nextDigitValue = num / (power / 10) % 10;
				if (nextDigitValue == 0)
				{
					++counter;

					// Check for 3 digit size change
					if (power / 100 > 0)
					{
						const int nextNextDigitValue = num / (power / 100) % 10;
						if (nextNextDigitValue == 0)
						{
							++counter;
						}
					}
				}
			}
		}
		else if (digitValue == 9)
		{
			--counter;
		}

		// #NOTE num is guaranteed to be les than 4000
		if (digitValue == 4)
		{
			char numeral = 0;
			for (size_t i = 0; i < sizeof(chars) / sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num += values[i];
					numeral = chars[i];
					break;
				}
			}
			returnStr.append(1, numeral);
		}
		else if (digitValue == 9)
		{
			char numeral = 0;
			for (size_t i = 0; i < sizeof(chars) / sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num += values[i+1];
					numeral = chars[i+1];
					break;
				}
			}
			returnStr.append(1, numeral);
		}
		else
		{
			char numeral = 0;
			for (size_t i = 0; i < sizeof(chars)/sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num -= values[i];
					numeral = chars[i];
					break;
				}
			}
			returnStr.append(1, numeral);
		}
	}

	return returnStr;
}

std::string IntegerToRoman_v2(int num)
{
	// DIFF Fewer g_iterations looking for numeral value

	int numCopy = num;
	int numDigits = 0;
	while (numCopy)
	{
		numCopy /= 10;
		++numDigits;
	}

	unsigned short values[] = { 1000, 500, 100, 50, 10, 5, 1 };
	unsigned char chars[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

	std::string returnStr;
	int counter = 0;

	int lowestNumeral = 0; // #TODO Saves g_iterations reliably?

	while (num)
	{
		const int power = pow(10, numDigits - counter - 1);
		const int digitValue = num / power;
		const int digitPower = digitValue * power;

		if (digitValue == 1 || digitValue == 5)
		{
			++counter;

			// Check for 2 digit size change
			if (power / 10 > 0)
			{
				const int nextDigitValue = num / (power / 10) % 10;
				if (nextDigitValue == 0)
				{
					++counter;

					// Check for 3 digit size change
					if (power / 100 > 0)
					{
						const int nextDigitValue = num / (power / 100) % 10;
						if (nextDigitValue == 0)
						{
							++counter;
						}
					}
				}
			}
		}
		else if (digitValue == 9)
		{
			--counter;
		}

		// #NOTE num is guaranteed to be les than 4000
		if (digitValue == 4)
		{
			char numeral = 0;
			for (size_t i = lowestNumeral; i < sizeof(chars) / sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num += values[i];
					numeral = chars[i];
					lowestNumeral = i - 1; // Dangerous if num is greater than 1000
					break;
				}
			}
			returnStr.append(1, numeral);
		}
		else if (digitValue == 9)
		{
			char numeral = 0;
			for (size_t i = lowestNumeral; i < sizeof(chars) / sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num += values[i + 1];
					numeral = chars[i + 1];
					lowestNumeral = i - 1; // Dangerous if num is greater than 1000
					break;
				}
			}
			returnStr.append(1, numeral);
		}
		else
		{
			char numeral = 0;
			for (size_t i = lowestNumeral; i < sizeof(chars) / sizeof(char); i++)
			{
				if (values[i] <= digitPower)
				{
					num -= values[i];
					numeral = chars[i];
					lowestNumeral = i;
					break;
				}
			}
			returnStr.append(1, numeral);
		}
	}

	return returnStr;
}

std::string IntegerToRoman_v3(int num)
{
	// DIFF 1 for loop, condensed code

	int numCopy = num;
	int startingDigits = 0;

	while (numCopy)
	{
		numCopy /= 10;
		++startingDigits;
	}

	unsigned short values[] = { 1000, 500, 100, 50, 10, 5, 1 };
	unsigned char chars[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

	std::string returnStr;
	int ProcessedDigits = 0;

	int lowestNumeral = 0;

	while (num)
	{
		const int power = pow(10, startingDigits - ProcessedDigits - 1);
		const int digitValue = num / power;
		const int digitPower = digitValue * power;

		if (digitValue == 1 || digitValue == 5)
		{
			++ProcessedDigits;

			// Check for 2 digit size change
			if (power / 10 > 0)
			{
				const int nextDigitValue = num / (power / 10) % 10;
				if (nextDigitValue == 0)
				{
					++ProcessedDigits;

					// Check for 3 digit size change
					if (power / 100 > 0)
					{
						const int nextDigitValue = num / (power / 100) % 10;
						if (nextDigitValue == 0)
						{
							++ProcessedDigits;
						}
					}
				}
			}
		}

		for (size_t i = lowestNumeral; i < sizeof(chars) / sizeof(char); i++)
		{
			if (values[i] <= digitPower)
			{
				const char offsetIfNine = digitValue == 9 ? 1 : 0;
				if (digitValue == 4 || offsetIfNine)
				{
					num += values[i + offsetIfNine];
					lowestNumeral = i - 1; // Dangerous if num is greater than 1000
					ProcessedDigits -= offsetIfNine; // Added another digit for next iteration to process
				}
				else
				{
					num -= values[i];
					lowestNumeral = i;
				}
				returnStr.append(1, chars[i + offsetIfNine]);
				break;
			}
		}
	}

	return returnStr;
}

std::string IntegerToRoman_v4(int num)
{
	// DIFF Iteration from NeetCode example, looking for implementation optimizations

	std::pair<std::string, int> symList[] = {
		{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
		{"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
		{"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
		{"M", 1000}
	};

	std::string returnStr;

	const int range = sizeof(symList) / sizeof(std::pair<std::string, int>);
	for (int i = range - 1; i >= 0; i--)
	{
		const int count = num / symList[i].second;
		if (count)
		{
			returnStr.append(count, symList[i].first[0]);
			if (symList[i].first.size() == 2)
			{
				returnStr.append(1, symList[i].first[1]);
			}
			num %= symList[i].second;
		}
	}

	return returnStr;
}

std::string IntegerToRoman_v5(int num)
{
	// DIFF 2nd iteration from NeetCode example, using a barebones char[] and pointer manipulation

	char arr[] = {
		// Bytes stored little endian
		'M', '0', 0b11101000,	0b11, // 4 byte rows
		'C', 'M', 0b10000100,	0b11,
		'D', '0', 0b11110100,	0b1,
		'C', 'D', 0b10010000,	0b1,
		'C', '0', 100,			0b0,
		'X', 'C', 90,			0b0,
		'L', '0', 50,			0b0,
		'X', 'L', 40,			0b0,
		'X', '0', 10,			0b0,
		'I', 'X', 9,			0b0,
		'V', '0', 5,			0b0,
		'I', 'V', 4,			0b0,
		'I', '0', 1,			0b0
	};

	std::string returnStr;

	constexpr int stepSize = 4; // Bytes per arr row
	constexpr int range = sizeof(arr) / stepSize * stepSize;

	for (size_t i = 0; i < range; i += stepSize)
	{
		const short value = *(reinterpret_cast<short*>(&arr[i + 2]));
		const int count = num / value;

		if (count)
		{
			returnStr.append(count, arr[i]);
			if (arr[i+1] != '0')
			{
				returnStr.append(1, arr[i+1]);
			}
			num %= value;
		}
	}

	return returnStr;
}

std::string IntegerToRoman_NeetCode_MathI(int num)
{
	std::vector<std::pair<std::string, int>> symList = {
		{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
		{"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
		{"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
		{"M", 1000}
	};

	std::string res = "";
	for (int i = symList.size() - 1; i >= 0; i--) {
		const int count = num / symList[i].second;
		if (count > 0) {
			res.append(count, symList[i].first[0]);
			if (symList[i].first.size() == 2) res.append(1, symList[i].first[1]);
			num %= symList[i].second;
		}
	}

	return res;
}

std::string IntegerToRoman_NeetCode_MathII(int num)
{
	std::string thousands[] = { "", "M", "MM", "MMM" };
	std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	std::string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

	return thousands[num / 1000] +
		hundreds[(num % 1000) / 100] +
		tens[(num % 100) / 10] +
		ones[num % 10];
}

typedef std::string(*SolutionFuncPtr)(int);

#include "Helpers.h"

void main_IntegerToRoman()
{
	SolutionFuncPtr solutionFunc = IntegerToRoman_v5;

	// LeetCode cases
	assert(strcmp(solutionFunc(58).c_str(), "LVIII") == 0);
	assert(strcmp(solutionFunc(3749).c_str(), "MMMDCCXLIX") == 0);
	assert(strcmp(solutionFunc(901).c_str(), "CMI") == 0);
	assert(strcmp(solutionFunc(140).c_str(), "CXL") == 0);

	// My cases
	assert(strcmp(solutionFunc(54).c_str(), "LIV") == 0);
	assert(strcmp(solutionFunc(501).c_str(), "DI") == 0);
	assert(strcmp(solutionFunc(99).c_str(), "XCIX") == 0);

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		IntegerToRoman_v1,
		IntegerToRoman_v2,
		IntegerToRoman_v3,
		IntegerToRoman_v4,
		IntegerToRoman_v5,

		IntegerToRoman_NeetCode_MathI,
		IntegerToRoman_NeetCode_MathII
	};

	RunSolutions(funcs, "MMMDCCXLIX", 3749);

	int bp = 0;
}

int main() { main_IntegerToRoman(); };