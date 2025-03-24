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

// Random
void SeedRand(int seed);
int RandomInRange(int rangeMin, int rangeMax);

// Numbers
unsigned char NumberOfDigits(int Value, int Base);
