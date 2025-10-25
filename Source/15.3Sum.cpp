
#include <assert.h>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/3sum/

// bool UniqueValues(const std::vector<std::vector<int>>& indices, int left, int middle, int right)
// {
//     const int arr[3] = { left, middle, right };
//
//     for (size_t i = 0; i < indices.size(); i++)
//     {
//         int matches = 0;
//
//         for (size_t j = 0; j < indices[i].size(); j++)
//         {
//             for (size_t k = 0; k < 3; k++)
//             {
//                 if (indices[i][j] == arr[k])
//                 {
//                     matches += 1;
//                     break;
//                 }
//             }
//         }
//
//         if (matches > 2)
//         {
//             return false;
//         }
//     }
//
//     return true;
// }

bool UniqueValues(const std::vector<std::vector<int>>& indices, int left, int middle, int right)
{
    std::vector<int> arr = { left, middle, right };

    for (size_t i = 0; i < indices.size(); i++)
    {
        int matches = 0;

        for (size_t j = 0; j < indices[i].size(); j++)
        {
            for (size_t k = 0; k < arr.size(); k++)
            {
                if (indices[i][j] == arr[k])
                {
                    // #NOTE 0,0,0 can't be added because 3 matches are generated
                    matches += 1;
                    arr.erase(arr.begin() + k);
                    --j;
                    break;
                }
            }
        }

        if (matches > 2)
        {
            return false;
        }
    }

    return true;
}

std::vector<std::vector<int>> ThreeSum_v1(const std::vector<int>& nums)
{
    // #NOTE Naive solution. No sorting

    std::vector<std::vector<int>> triplets;

    for (int i = 0; i < nums.size(); i++)
    {
        const int left = nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            const int middle = nums[j];

            for (int k = j + 1; k < nums.size(); k++)
            {
                const int right = nums[k];

                if (left + middle + right  == 0)
                {
                    if (UniqueValues(triplets, left, middle, right))
                    {
                        triplets.push_back({ { left, middle, right } });
                    }
                }
            }
        }
    }

    return triplets;
}

#include "Testing.h"
typedef std::vector<std::vector<int>>(*SolutionFuncPtr)(const std::vector<int>&);

void main_3Sum()
{
    SolutionFuncPtr solutionFunc = ThreeSum_v1;

    // LeetCode cases
    std::vector<int> input = { -1, 0, 1, 2, -1, -4 };
    std::vector<std::vector<int>> output = {
        {-1, 0, 1 },
        {-1, 2, -1}
    };
    // assert(Equal(solutionFunc(input), output));
    //
    // input = { 0, 1, 1 };
    // output = { };
    // assert(Equal(solutionFunc(input), output));
    //
    // input = { 0, 0, 0 };
    // output = { { 0, 0, 0 } };
    // assert(Equal(solutionFunc(input), output));

    input = { 0, 3, 0, 1, 1, -1, -5, -5, 3, -3, -3, 0 };
    output = {
        { -3, 0, 3 },
        { -1, 0, 1 },
        { 0, 0, 0 }
    };
    assert(Equal(solutionFunc(input), output));

    // My cases
    // assert(solutionFunc() == true);

    // Test solution performance
    std::vector<SolutionFuncPtr> funcs = {
        ThreeSum_v1,
    };

    RunSolutions(funcs, output, input);

    int bp = 0;
}

int main() { main_3Sum(); }