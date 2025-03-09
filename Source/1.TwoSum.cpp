
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

#include "Helpers.h"

// https://leetcode.com/problems/two-sum/description/

typedef std::vector<int>(*SolutionFuncPtr)(const std::vector<int>&, int);

// Submitted 09/01/24 9:13am
// Runtime of 304ms (26.33%), with RAM usage of 10.6MB (78.58%)
std::vector<int> twoSum_v1(const std::vector<int>& nums, int target) {

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
std::vector<int> twoSum_v2(const std::vector<int>& nums, int target) {

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
std::vector<int> twoSum_v3(const std::vector<int>& nums, int target) {

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
std::vector<int> twoSum_v4(const std::vector<int>& nums, int target) {

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
std::vector<int> twoSumv5(const std::vector<int>& nums, int target) {

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

struct twoSumv1_Input
{
	twoSumv1_Input()
	{
		target = 0;
	}

	twoSumv1_Input(std::vector<int> argument, int aTarget)
	{
		values = argument;
		target = aTarget;
	}

	std::vector<int> values;
	int target;
};

struct twoSumv1_Output
{
	twoSumv1_Output()
	{
		int bp = 1;
	}

	twoSumv1_Output(const std::vector<int>& argument)
	{
		results = argument;
	}

	bool Equal(const twoSumv1_Output& out) const // #TODO Could be made into problems helper function
	{
		// #TODO Maybe add problems flag for argument order dependency issues.
		// Like strict or loose, where the order can matter but doesn't have to
		// as long as each value appears the same m_number of times in each list
		// and each list has problems copy of each unique value.

		if (out.results.size() != results.size())
			return false;

		for (size_t i = 0; i < out.results.size(); i++)
		{
			if (out.results.at(i) != results.at(i))
			{
				return false;
			}
		}
		return true;
	}

	std::vector<int> results;
};

struct ProblemCaseData
{
	ProblemCaseData(const ProblemCaseData& other)
	{
		input = other.input;
		expectedOutput = other.expectedOutput;
	}

	ProblemCaseData(twoSumv1_Input aInput, twoSumv1_Output aOutput)
	{
		input = aInput;
		expectedOutput = aOutput;
	}

	bool operator = (ProblemCaseData other)
	{
		input = other.input;
		expectedOutput = other.expectedOutput;
	}

	twoSumv1_Input input;
	twoSumv1_Output expectedOutput;
};

std::map<SolutionFuncPtr, std::string> functions = {
	{ twoSum_v1,STRINGIFY(twoSum_v1) },
	{ twoSum_v2,STRINGIFY(twoSum_v2) },
	{ twoSum_v3,STRINGIFY(twoSum_v3) },
	{ twoSum_v4,STRINGIFY(twoSum_v4) }
};

void TwoSum_Run(int solutionNumber)
{
	// #TODO Option to swap iterators to loop over all solutions first, or all data sets first

	std::vector<SolutionFuncPtr> solutionFuncPtrs = {
		twoSum_v1,
		twoSum_v2,
		twoSum_v3,
		twoSum_v4
	};

	std::vector<ProblemCaseData> problemDataSet = {
		ProblemCaseData(twoSumv1_Input({ 2,7,11,15 }, 9), twoSumv1_Output({ 0, 1 })), // LeetCode
		ProblemCaseData(twoSumv1_Input({ 3,2,4 }, 6),	 twoSumv1_Output({ 1, 2 })),
		ProblemCaseData(twoSumv1_Input({ 3,3, }, 6),		 twoSumv1_Output({ 0, 1 })),

		ProblemCaseData(twoSumv1_Input({ 3,7,9,4,30,-7,5,2,3,8 }, 15),		 twoSumv1_Output({ 1, 9 })), // My own cases
	};

	std::vector<double> solutionSumTime(solutionFuncPtrs.size(), 0.0);

	bool encounteredResultError = false;
	const int iterations = 50;

	for (size_t solutionFuncPtrsIndex = 0; solutionFuncPtrsIndex < solutionFuncPtrs.size(); solutionFuncPtrsIndex++)
	{
		std::vector<double> functionRuntimes(problemDataSet.size() * iterations, 0.0);

		for (size_t i = 0; i < problemDataSet.size(); i++)
		{
			for (size_t iteration = 0; iteration < iterations; iteration++)
			{
				auto input = problemDataSet[i].input;
				std::cout << "\n\n" << functions.find(solutionFuncPtrs[solutionFuncPtrsIndex])->second.c_str() << " is starting with input: ";
				PrintVector(problemDataSet[i].input.values);
				std::cout << " and " << problemDataSet[i].input.target;

				const double startTime = Now();
				auto output = functions.find(solutionFuncPtrs[solutionFuncPtrsIndex])->first(input.values, input.target);
				const double endTime = Now();

				std::cout << "\n" << functions.find(solutionFuncPtrs[solutionFuncPtrsIndex])->second.c_str() << " ended with output: ";
				PrintVector(output);
				if (!Equal(output, problemDataSet[i].expectedOutput.results))
				{
					std::cout << "\nInvalid output!\n";
					encounteredResultError = true;
				}

				const double elapsedTime = endTime - startTime;
				PrintA("\nDuration: %.12f sec", elapsedTime);
				functionRuntimes[i + (iteration * problemDataSet.size())] = elapsedTime;
			}
		}

		const double sumTime = SumVector(functionRuntimes);
		std::cout << "\n" << functions.find(solutionFuncPtrs[solutionFuncPtrsIndex])->second.c_str() << " ran " << problemDataSet.size() <<
			" cases with " << iterations << " iterations for total " << sumTime << " sec and avg " << sumTime / problemDataSet.size() << " sec";

		solutionSumTime[solutionFuncPtrsIndex] = sumTime;
	}

	std::cout << "\n";
	for (size_t i = 0; i < solutionFuncPtrs.size(); i++)
	{
		std::cout << "\nTest " << functions.find(solutionFuncPtrs[i])->second << " total " << solutionSumTime[i] <<
			" sec and avg " << solutionSumTime[i] / iterations << " sec";
	}

	if (encounteredResultError) PrintA("\nEncountered error(s)\n");
}

// #TODO Review above code and look to delete all but solutions
#include "Problem.h"

ProblemTwoSum::ProblemTwoSum(const std::string& m_name, unsigned short m_number) :
	Problem(m_name, m_number)
{
	vecOfInputPairs = {
		{ { 2,7,11,15 }, 9 },
		{ { 3,2,4 }, 6 },
		{ { 3,3, }, 6 },
		{ { 3,7,9,4,30,-7,5,2,3,8 }, 15 } // Custom case
	};

	vecOfOutputsVecs = {
		{ 0, 1 },
		{ 1, 2 },
		{ 0, 1 },
		{ 1, 9 } // Custom case
	};

	if (vecOfInputPairs.size() != vecOfOutputsVecs.size())
	{
		std::cout << "Mismatching sizes!"; // #TODO Error checking/handling
	}

	solutions = {
		{ twoSum_v1, "twoSum_v1 O(n^2)"},
		{ twoSum_v2, "twoSum_v2 O(n^2) with caching"},
		{ twoSum_v3, "twoSum_v3 O(n)"},
		{ twoSum_v4, "twoSum_v4 O(n) using unordered map"}
	};
	m_numberOfSolutions = (unsigned short)solutions.size();
}

void ProblemTwoSum::Run(unsigned char solutionNumber)
{
	const unsigned char chosenSolutionIndex = solutionNumber - 1;

	std::vector<double> inputOutputCaseDuration(vecOfInputPairs.size(), 0.0);
	std::vector<std::vector<int>> results(vecOfInputPairs.size(), {});

	std::cout << "\n" << GetNumber() << "." << GetName() << " solution #" << (int)solutionNumber << "\n";

	for (size_t i = 0; i < vecOfInputPairs.size(); i++)
	{
		std::cout << "[";
		for (size_t j = 0; j < vecOfInputPairs[i].first.size(); j++)
		{
			std::cout << vecOfInputPairs[i].first[j];
			if (j < vecOfInputPairs[i].first.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "] ";
		std::cout << vecOfInputPairs[i].second << "\n";

		inputOutputCaseDuration[i] = Now();

		results[i] = solutions[chosenSolutionIndex].first(vecOfInputPairs[i].first, vecOfInputPairs[i].second);

		inputOutputCaseDuration[i] = Now() - inputOutputCaseDuration[i];
	}

	// #TODO Test solution on all inputs/outputs

	std::cout << "\n";
	for (size_t i = 0; i < vecOfInputPairs.size(); i++)
	{
		// Validate results
		bool passed = true;
		for (size_t j = 0; j < results[i].size(); j++)
		{
			if (results[i][j] != vecOfOutputsVecs[i][j])
			{
				passed = false;
				break;
			}
		}

		// #TODO Print output and time for each case (later, ram usage as well)
		std::cout << "Solution " << (int)solutionNumber << (passed ? ": PASSED" : ": FAILED") << " in " << inputOutputCaseDuration[i] << " time\n";
	}
}