
#include <assert.h>
#include <cmath>
#include <string>

// #include "Helpers.h"

// Link to leetcode problem https://leetcode.com/problems/integer-to-roman/

// Complexity O(n), Memory O(1)
// Submitted 23/03/25 9:15pm
// Runtime of 0ms? (100%)?, with RAM usage of 8.68MB (90.84%)
std::string IntToRoman_v1(int num)
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

	int lowestNumeral = 0; // #TODO Saves iterations reliably?

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
					// lowestNumeral = i - 1; // Dangerous if num is greater than 1000
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
					// lowestNumeral = i - 1; // Dangerous if num is greater than 1000
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
					// lowestNumeral = i;
					break;
				}
			}
			returnStr.append(1, numeral);
		}
	}

	return returnStr;
}

typedef std::string(*SolutionFuncPtr)(int);

void main_IntegerToRoman()
{
	SolutionFuncPtr solutionFunc = IntToRoman_v1;

	// LeetCode cases
	// assert(strcmp(solutionFunc(58).c_str(), "LVIII") == 0);
	// assert(strcmp(solutionFunc(3749).c_str(), "MMMDCCXLIX") == 0);
	// assert(strcmp(solutionFunc(901).c_str(), "CMI") == 0);
	assert(strcmp(solutionFunc(140).c_str(), "CXL") == 0);

	// My cases
	// assert(strcmp(solutionFunc(54).c_str(), "LIV") == 0);
	// assert(strcmp(solutionFunc(501).c_str(), "DI") == 0);
	// assert(strcmp(solutionFunc(99).c_str(), "XCIX") == 0);
}

int main() { main_IntegerToRoman(); };