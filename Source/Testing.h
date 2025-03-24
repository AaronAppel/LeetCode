#pragma once

#include <iostream>
#include <string>

#define STRINGIFY(x) #x

constexpr int g_iterations = 500;

template <typename T, typename U, typename ... V>
void RunSolutions(const std::vector<T>& functionPtrs, U expectedOutput, V ... args)
{
	for (size_t i = 0; i < functionPtrs.size(); i++)
	{
		double runningSum = 0.;

		for (size_t j = 0; j < g_iterations; j++)
		{
			double start = NowMs();
			functionPtrs[i](args...);
			double stop = NowMs();
			runningSum += stop - start;
		}

		std::cout << i << ": " << runningSum << "\n";
	}
}

template <typename T, typename ... V>
void TestSolutions(const std::vector<T>& functionPtrs, std::string expectedOutput, V ... args)
{
	for (size_t i = 0; i < functionPtrs.size(); i++)
	{
		for (size_t j = 0; j < g_iterations; j++)
		{
			if (strcmp(functionPtrs[i](args...).c_str(), expectedOutput) != 0);
			{
				std::cout << STRINGIFY(functionPtrs[i]) << ": FAILED\n";
			}
		}

	}
}

template <typename T, typename U, typename ... V>
void TestSolutions(const std::vector<T>& functionPtrs, U expectedOutput, V ... args)
{
	for (size_t i = 0; i < functionPtrs.size(); i++)
	{
		for (size_t j = 0; j < g_iterations; j++)
		{
			if (functionPtrs[i](args...) != expectedOutput);
			{
				std::cout << STRINGIFY(functionPtrs[i]) << ": FAILED\n";
			}
		}
	}
}
