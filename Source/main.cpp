
#include <iostream>
#include <map>

#define LESSON_CODE 1

#include "Problem.h"

Problem* problems[] = {
	new ProblemTwoSum("TwoSum", 1),
	new ProblemAddTwoNumbers("AddTwoNumbers", 2)
};
const int count = sizeof(problems) / sizeof(Problem*);

unsigned short GetNumberFromUser();
void PrintProblemList();

int main_unused()
{
	unsigned short problemNumber = 0;

	do
	{
		PrintProblemList();
		std::cout << "\n\nEnter problem number or 0 to exit: ";
		problemNumber = GetNumberFromUser();

		if (problemNumber == 0)
			return 0;

		bool foundProblem = false;
		for (size_t i = 0; i < count; i++)
		{
			if (problemNumber == problems[i]->GetNumber())
			{
				foundProblem = true;
				int solutionNumber = 0;
				do
				{
					if (problems[i]->GetNumberOfSolutions() < 1)
					{
						std::cout << "\nProblem #" << problems[i]->GetNumber() << " has no solutions!\n";
						break;
					}
					else
					{
						std::cout << "\nSolutions for problem #" << problems[i]->GetNumber() << ":\n";
						problems[i]->PrintSolutions();
					}

					std::cout << "\nEnter solution number or 0 for problem list: ";
					solutionNumber = GetNumberFromUser();

					if (solutionNumber)
					{
						if (solutionNumber > problems[i]->GetNumberOfSolutions())
						{
							// #TODO solution not found, break
							std::cout << "Solution number " << solutionNumber << " not found!\n";
						}
						else
						{
							problems[i]->Run(solutionNumber);
						}
					}

				} while (solutionNumber > 0);
			}
		}

		if (!foundProblem)
		{
			std::cout << "Problem number " << (int)problemNumber << " not found!\n";
		}

	} while (problemNumber > 0);

	const int count = sizeof(problems) / sizeof(Problem*);
	for (size_t i = 0; i < count; i++)
	{
		delete problems[i];
	}

	return 0;
}

unsigned short GetNumberFromUser()
{
	std::string userInput;
	std::cin >> userInput;

	if (userInput.empty())
	{
		return UINT16_MAX; // Invalidate input. Avoid exception in stoi
	}

	for (size_t i = 0; i < userInput.size(); i++)
	{
		if (userInput[i] > 57 || userInput[i] < 48)
		{
			return UINT16_MAX; // Invalidate input. Avoid exception in stoi
		}
	}
	return std::stoi(userInput);
}

void PrintProblemList()
{
	const int count = sizeof(problems) / sizeof(Problem*);

	std::cout << "\nProblems:\n";
	for (size_t i = 0; i < count; i++)
	{
		std::cout << problems[i]->GetNumber() << "." << problems[i]->GetName();
		if (i < count - 1)
		{
			std::cout << "\n";
		}
	}
}
