#pragma once

#include <iostream>
#include <vector>

// Math
double SumVector(const std::vector<double>& doubles);

// Time
double Now();
double NowMs();

// #TODO RAM usage helpers

// Printing
#define PrintA(msg, ...) printf_s(msg, __VA_ARGS__)
void Print(const char* msg, ...);

template <typename T>
void PrintVector(const std::vector<T>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i > 0 && i < vector.size() - 1)
			std::cout << ",";
		std::cout << vector[i];
	}
}

// Equality
bool Equal(std::vector<int> a, std::vector<int> b, bool orderDependent=true);

template <typename T>
bool Equal(const std::vector<T>& a, const std::vector<T>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool Equal(const std::vector<std::vector<T>>& a, const std::vector<std::vector<T>>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	for (size_t i = 0; i < a.size(); i++)
	{
		if (!Equal<T>(a[i], b[i]))
		{
			return false;
		}
	}
	return true;
}

// Random
void SeedRand(int seed);
int RandomInRange(int rangeMin, int rangeMax);

// Numbers
unsigned char NumberOfDigits(int Value, int Base);
