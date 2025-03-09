#pragma once

#include <iostream> // For std::cout
#include <string>
#include <vector>

class Problem
{
public:
	Problem(const std::string& m_name, unsigned short m_number) :
		m_name(m_name),
		m_number(m_number)
	{ }

	virtual void PrintSolutions()
	{
		std::cout << "\nSolutions:\n";
		for (size_t i = 0; i < m_numberOfSolutions; i++)
		{
			std::cout << "Solution " << i + 1 << "\n";
		}
	}

	virtual void Run(unsigned char solutionNumber) = 0;

	[[nodiscard]] const std::string& GetName() { return m_name; }
	[[nodiscard]] const short GetNumber() { return m_number; }
	[[nodiscard]] const short GetNumberOfSolutions() { return m_numberOfSolutions; }

private:
	std::string m_name = "";
	unsigned short m_number = 0;

protected:
	virtual void PrintResults()
	{
		std::cout << "\nSolution run completed\n";
	}

	unsigned short m_numberOfSolutions = 0;
	// #TODO Add -> unsigned short m_numberOfCaseIterations = 1;
};

class ProblemTwoSum : public Problem
{
public:
	ProblemTwoSum(const std::string& m_name, unsigned short m_number);

	virtual void Run(unsigned char solutionNumber) override;

private:
	std::vector<std::pair<std::vector<int>, int>> vecOfInputPairs;
	std::vector<std::vector<int>> vecOfOutputsVecs;

	typedef std::vector<int>(*SolutionFuncPtr)(const std::vector<int>&, int);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};

class ListNode;
class ProblemAddTwoNumbers : public Problem
{
public:
	ProblemAddTwoNumbers(const std::string& m_name, unsigned short m_number);

	virtual void Run(unsigned char solutionNumber) override;

private:
	typedef ListNode*(*SolutionFuncPtr)(ListNode* l1, ListNode* l2);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};

class ProblemContainsDuplicate : public Problem
{
public:
	ProblemContainsDuplicate(const std::string& m_name, unsigned short m_number);

	void PrintSolutions() override;
	virtual void Run(unsigned char solutionNumber) override;
	virtual void PrintResults() override;

private:
	std::vector<std::pair<std::vector<int>, bool>> inputOutputPairs;

	typedef bool(*SolutionFuncPtr)(std::vector<int>&);
	std::vector<std::pair<SolutionFuncPtr, std::string>> solutions;
};
