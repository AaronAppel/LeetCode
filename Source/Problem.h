#pragma once

#include <iostream> // For std::cout
#include <string>
#include <vector>

#include <any> // #TODO Testing generic type handling
#include <tuple>

class Problem
{
public:
	Problem(const std::string& m_name, unsigned short m_number) :
		m_name(m_name),
		m_number(m_number)
	{ }

	void Run(unsigned char solutionNumber)
	{
		RunInternal(solutionNumber);
		PrintResults();

		std::cout << "\nSolution run completed\n";
	}

	void PrintSolutions()
	{
		std::cout << "\nSolutions:\n";
		for (size_t i = 0; i < m_numberOfSolutions; i++)
		{
			std::cout << "Solution " << i + 1 << "\n";
		}
	}

	[[nodiscard]] const std::string& GetName() { return m_name; }
	[[nodiscard]] const short GetNumber() { return m_number; }
	[[nodiscard]] const short GetNumberOfSolutions() { return m_numberOfSolutions; }

protected:
	virtual void RunInternal(unsigned char solutionNumber) = 0;

	virtual void PrintResults()
	{
		std::cout << "\nSolution run completed\n";
	}

	unsigned short m_numberOfSolutions = 0;
	// #TODO Add -> unsigned short m_numberOfCaseIterations = 1;

	std::vector<std::pair<std::any, std::any>> solutionsAny;

	enum TupleIndex
	{
		FunctionPtr = 0,
		StringName,
		Input,
		Output
	};
	std::vector<std::tuple<std::any, std::string, std::any, std::any>> tuplesAny;

private:
	std::string m_name = "";
	unsigned short m_number = 0;
};

// 1. Two Sum
class ProblemTwoSum : public Problem
{
public:
	ProblemTwoSum(const std::string& m_name, unsigned short m_number);

protected:
	virtual void RunInternal(unsigned char solutionNumber) override;

private:
	std::vector<std::pair<std::vector<int>, int>> vecOfInputPairs;
	std::vector<std::vector<int>> vecOfOutputsVecs;

	typedef std::vector<int>(*SolutionFuncPtr)(const std::vector<int>&, int);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};

// 2. Add Two Numbers
class ListNode;
class ProblemAddTwoNumbers : public Problem
{
public:
	ProblemAddTwoNumbers(const std::string& m_name, unsigned short m_number);

protected:
	virtual void RunInternal(unsigned char solutionNumber) override;

private:
	typedef ListNode*(*SolutionFuncPtr)(ListNode* l1, ListNode* l2);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};

// 3. Longest Substring Without Repeating Characters

// 4. Median of Two Sorted Arrays

// 5. Longest Palindromic Substring

// 6. Zigzag Conversion
class ProblemZigzagConversion : public Problem
{
public:
	ProblemZigzagConversion(const std::string& m_name, unsigned short m_number);

	virtual void RunInternal(unsigned char solutionNumber) override;

	// virtual void PrintSolutions() override;
	// virtual void PrintResults() override;
};

// 217. Contains Duplicate
class ProblemContainsDuplicate : public Problem
{
public:
	ProblemContainsDuplicate(const std::string& m_name, unsigned short m_number);

	virtual void RunInternal(unsigned char solutionNumber) override;

private:
	// #TODO Find a way to add unique string names to solutions, without extra code in every problem
	void PrintSolutionsInternal();

	std::vector<std::pair<std::vector<int>, bool>> inputOutputPairs;

	typedef bool(*SolutionFuncPtr)(std::vector<int>&);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};