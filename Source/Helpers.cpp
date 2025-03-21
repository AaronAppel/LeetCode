#include "Helpers.h"

#include <Windows.h>
#include <profileapi.h>
#include <vector>
#include <iostream>
#include <fstream> // vsnprintf_s
#include <cstdarg> // va_start, va_end
#include <debugapi.h> // OuputDebugStringA(buffer)
#include <stdlib.h> // srand
#include <assert.h>

double SumVector(const std::vector<double>& doubles)
{
	double returnValue = 0.0;
	for (size_t i = 0; i < doubles.size(); i++)
	{
		returnValue += doubles[i];
	}
	return returnValue;
}

double Now()
{
	return NowMs() * 1000.0;
}

double NowMs()
{
	unsigned __int64 freq;
	unsigned __int64 time;

	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&time);

	return (double)time / freq;
}

void Print(const char* msg, ...)
{
#define MAX_MESSAGE 1024
	char buffer[MAX_MESSAGE];
	va_list arg;
	va_start(arg, msg);
	vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, msg, arg);
	va_end(arg);

	// vsnprintf_s might do this, but docs are unclear
	buffer[MAX_MESSAGE - 1] = 0; // #TODO Should this be '\0'?
	OutputDebugStringA(buffer);

	// fprintf(stderr, msg);
}

bool Equal(std::vector<int> a, std::vector<int> b, bool orderDependent)
{
	// Potential problem to solve
	// #TODO if (!orderDependent) Use a map maybe to track of list 1 items an occurrences, then
	// compare occurrences in list2 and track 0 allocation count?

	if (a.size() != b.size())
		return false;

	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void SeedRand(int seed)
{
	srand(seed);
}

int RandomInRange(int rangeMin, int rangeMax)
{
	assert(rangeMax - rangeMin);
	return (rand() % (rangeMax - rangeMin)) + rangeMin;
}

unsigned char NumberOfDigits(int Value, int Base)
{
	if (Value == 0)
	{
		return 1;
	}

	unsigned char digits = 0;

	while (Value != 0)
	{
		Value /= Base;
		++digits;
	}

	return digits;
}
