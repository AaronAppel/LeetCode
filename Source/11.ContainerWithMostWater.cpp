
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/container-with-most-water/

int ContainerWithMostWater_v1(std::vector<int>&height)
{
	return 0;
}

typedef int(*SolutionFuncPtr)(std::vector<int>&);

void main_ContainerWithMostWater()
{
	SolutionFuncPtr solutionFunc = ContainerWithMostWater_v1;
	// assert(solutionFunc() == true);
}

// int main() { main_ContainerWithMostWater(); }
