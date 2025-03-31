
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/fizz-buzz/

// Complexity O(n), Memory O(n)
// Submitted 27/03/25 6:59pm
// Runtime of 3ms (29.56%), with RAM usage of 11.85MB (15.63%)
std::vector<std::string> FizzBuzz_v1(int num)
{
	// NAIVE

	std::vector<std::string> returnStrings;
	returnStrings.reserve(num);

	for (size_t i = 1; i < num + 1; i++)
	{
		if (i % 3 == 0)
		{
			returnStrings.emplace_back("Fizz");
		}

		if (i % 5 == 0)
		{
			if (i % 3 == 0)
			{
				returnStrings[returnStrings.size() - 1].append("Buzz");
			}
			else
			{
				returnStrings.emplace_back("Buzz");
			}
		}
		else if (i % 3 != 0)
		{
			returnStrings.emplace_back(std::to_string(i));
		}
	}

	return returnStrings;
}

std::vector<std::string> FizzBuzz_v2(int num)
{
	// DIFF Combined check gets its own statement

	std::vector<std::string> returnStrings;
	returnStrings.reserve(num);

	for (size_t i = 1; i < num + 1; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			returnStrings.emplace_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			returnStrings.emplace_back("Fizz");

		}
		else if (i % 5 == 0)
		{
			returnStrings.emplace_back("Buzz");
		}
		else
		{
			returnStrings.emplace_back(std::to_string(i));
		}
	}

	return returnStrings;
}

// Complexity O(n), Memory O(n)
// Submitted 27/03/25 7:18pm
// Runtime of 2ms (42.21%), with RAM usage of 11.14MB (85.39%)
// 2nd run was 0ms, so LeetCode is not reliable enough to use for metrics
std::vector<std::string> FizzBuzz_v3(int num)
{
	// DIFF Get hacky with it. Make some assumptions to skip % operations.
	// Only the "FizzBuzz" case can reliably skip the next iteration

	std::vector<std::string> returnStrings;
	returnStrings.reserve(num);

	for (size_t i = 1; i < num + 1; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			returnStrings.emplace_back("FizzBuzz");
			if (i < num)
			{
				returnStrings.emplace_back(std::to_string(i + 1));
				returnStrings.emplace_back(std::to_string(i + 2));
				i += 2;
			}
		}
		else if (i % 3 == 0)
		{
			returnStrings.emplace_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			returnStrings.emplace_back("Buzz");
		}
		else
		{
			returnStrings.emplace_back(std::to_string(i));
		}
	}

	return returnStrings;
}

#include "Helpers.h"
#include "Testing.h"

typedef std::vector<std::string>(*SolutionFuncPtr)(int);

void main_FizzBuzz()
{
	SolutionFuncPtr solutionFunc = FizzBuzz_v3;

	// LeetCode cases
	assert(Equal(solutionFunc(3), { "1", "2", "Fizz" } ));
	assert(Equal(solutionFunc(5), { "1", "2", "Fizz", "4", "Buzz" }));
	assert(Equal(solutionFunc(15), { "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz" }));
	assert(Equal(solutionFunc(100), { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16","17","Fizz","19","Buzz","Fizz","22","23","Fizz","Buzz","26","Fizz","28","29","FizzBuzz","31","32","Fizz","34","Buzz","Fizz","37","38","Fizz","Buzz","41","Fizz","43","44","FizzBuzz","46","47","Fizz","49","Buzz","Fizz","52","53","Fizz","Buzz","56","Fizz","58","59","FizzBuzz","61","62","Fizz","64","Buzz","Fizz","67","68","Fizz","Buzz","71","Fizz","73","74","FizzBuzz","76","77","Fizz","79","Buzz","Fizz","82","83","Fizz","Buzz","86","Fizz","88","89","FizzBuzz","91","92","Fizz","94","Buzz","Fizz","97","98","Fizz","Buzz" }));

	// Test solution performance
	std::vector<SolutionFuncPtr> funcs = {
		FizzBuzz_v1,
		FizzBuzz_v2,
		FizzBuzz_v3
	};

	RunSolutions(funcs, std::vector<std::string>({ "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz" } ), 15);

	int bp = 0;
}

// int main() { main_FizzBuzz(); };
