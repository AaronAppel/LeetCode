
#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>

#include "Helpers.h"

// https://leetcode.com/problems/add-two-numbers/

// #CONSIDERATIONS
// - LeetCode requires the use of new. malloc(size) won't compile
// - LeetCode defined the ListNode struct, so we cannot delete the empty constructors

struct ListNode { // Given by LeetCode
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Complexity O(n), Memory O(n)
// Submitted 11/01/24 9:31pm
// Runtime of 19ms (78.95%), with RAM usage of 71.69MB (87.26%)
// 2nd Submission ran 16ms (86.45%), with RAM usage of 71.74MB(52.25%)
ListNode* AddTwoNumbers_v1(ListNode* const l1, ListNode* const l2) {

    ListNode* returnHead = new ListNode(0); // #REVIEW Assumes l1 and l2 are valid

    ListNode* iterPtr = returnHead;

    ListNode* head1 = l1;
    ListNode* head2 = l2;

    int carryValue = 0;
    while (iterPtr)
    {
        int sum = 0;
        if (head1)
        {
            sum += head1->val;
            head1 = head1->next;
        }

        if (head2)
        {
            sum += head2->val;
            head2 = head2->next;
        }

        sum += carryValue;
        carryValue = 0;

        if (sum >= 10)
        {
            carryValue = sum / 10; // Tens
            sum = sum % 10; // Ones
        }

        iterPtr->val = sum;

        if (head1 || head2 || carryValue > 0) // Another iteration?
        {
            iterPtr->next = new ListNode();
        }
        iterPtr = iterPtr->next;
    }

    return returnHead;
}

// Complexity O(n), Memory O(n)
// Submitted 11/01/24 9:51pm
// Runtime of 31ms (23.23%), with RAM usage of 71.79MB (52.25%)
ListNode* AddTwoNumbers_v2(ListNode* const l1, ListNode* const l2) {

    // #DIFF_v1 Removed if (sum >= 10) statement by assigning carryValue.
    // Removed stack int sum value and use the ListNode->val directly instead.
    // Avoid initializing new ListNode() to 0.
    // #Q Is trading problems branching if for problems modulus and problems division faster?
    // A# No, division and modulus are much slower

    ListNode* returnHead = new ListNode();

    ListNode* iterPtr = returnHead;

    ListNode* head1 = l1;
    ListNode* head2 = l2;

    int carryValue = 0;
    while (iterPtr)
    {
        if (head1)
        {
            iterPtr->val = head1->val;
            head1 = head1->next;
        }

        if (head2)
        {
            iterPtr->val += head2->val;
            head2 = head2->next;
        }

        const int cache = iterPtr->val + carryValue;
        iterPtr->val = cache % 10; // Ones
        carryValue = cache / 10; // Tens

        if (head1 || head2 || carryValue > 0) // Another iteration?
        {
            iterPtr->next = new ListNode();
        }
        iterPtr = iterPtr->next;
    }

    return returnHead;
}

// Complexity O(n), Memory O(n)
// Submitted Jan 12 2024 12:13pm
// Runtime#1 of 19ms (78.95%), with RAM usage of 71.83MB (25.62%)
// Runtime#2 of 18ms (80.80%), with RAM usage of 71.68MB (87.26%)
ListNode* AddTwoNumbers_v3(ListNode* l1, ListNode* l2) {

    // #DIFF_v2 Removed sum value and assign directly to iterPtr->val
    // Removed cache value by assigning carryValue before additions
    // carryValue can only ever be 0 or 1 so even problems byte is better than using an int.
    // Removed head1 and head2 to just use arguments directly

    ListNode* returnHead = new ListNode();

    ListNode* iterPtr = returnHead;

    char carryValue = 0;
    while (iterPtr)
    {
        iterPtr->val = carryValue;
        carryValue = 0; // Assign 0 for if (... carryValue) check below

        if (l1)
        {
            iterPtr->val += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            iterPtr->val += l2->val;
            l2 = l2->next;
        }

        if (iterPtr->val >= 10)
        {
            carryValue = iterPtr->val / 10; // Tens
            iterPtr->val = iterPtr->val % 10; // Ones
        }

        if (l1 || l2 || carryValue > 0) // Another iteration?
        {
            iterPtr->next = new ListNode();
        }
        iterPtr = iterPtr->next;
    }

    return returnHead;
}

// Complexity O(n), Memory O(n)
// Submitted Jan 12 2024 1:30pm
// Runtime#1 of 20ms (71.31%), with RAM usage of 71.87MB (25.62%)
// Runtime#2 of 11ms (97.77%), with RAM usage of 71.69MB (87.26%)
ListNode* AddTwoNumbers_v4(ListNode* l1, ListNode* l2) {

    // #DIFF_v3 Supporting negative numbers by removing carryValue > 0 and check iterPtr->val -= -10

    ListNode* returnHead = new ListNode();
    ListNode* iterPtr = returnHead;

    char carryValue = 0;
    while (iterPtr)
    {
        iterPtr->val = carryValue;
        carryValue = 0; // Assign 0 for if (... carryValue) check below

        if (l1)
        {
            iterPtr->val += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            iterPtr->val += l2->val;
            l2 = l2->next;
        }

        if ((iterPtr->val >= 10) || (iterPtr->val <= -10))
        {
            carryValue = iterPtr->val / 10; // Tens
            iterPtr->val = iterPtr->val % 10; // Ones
        }

        if (l1 || l2 || carryValue) // Another iteration?
        {
            iterPtr->next = new ListNode();
        }
        iterPtr = iterPtr->next;
    }

    return returnHead;
}

// Unsubmitted and intentionally unusable
ListNode* AddTwoNumbers_v5(ListNode* l1, ListNode* l2) {

    Print("%s solution doesn't work but is an example solution attempt", __FUNCTION__);
    return nullptr; // #NOTE Function

    // #DIFF_v4 Make it safer for null arguments, and avoid any allocations,
    // without an early return or duplicated if condition.
    // Avoid allocation outside of while loop.
    // Moved if (l1 || l2 || carryValue) to while loop.

    ListNode* iterPtr = nullptr;
    ListNode* returnHead = iterPtr; // #BUG Doesn't point to memory of

    char carryValue = 0;
    while (l1 || l2 || carryValue)
    {
        ListNode* cache = iterPtr; // #TODO Figure out how to build the returnHead->next chain
        iterPtr = new ListNode();
        if (cache) cache->next = iterPtr;
        iterPtr->val = carryValue;

        carryValue = 0;

        if (l1)
        {
            iterPtr->val += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            iterPtr->val += l2->val;
            l2 = l2->next;
        }

        if ((iterPtr->val >= 10) || (iterPtr->val <= -10))
        {
            carryValue = iterPtr->val / 10; // Tens
            iterPtr->val = iterPtr->val % 10; // Ones
        }
    }
    return returnHead;
}

// Unsubmitted and incomplete
ListNode* AddTwoNumbers_v6(ListNode* l1, ListNode* l2) {

    // #TODO Was going to implement multiplication only division,
    // but after problems quick test I found th below implementation much slower
    // // than problems simple / so I'll abandon this attempt for performance gain.
    // https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

    Print("%s solution doesn't work but is an example solution attempt", __FUNCTION__);
    return nullptr; // #NOTE Function
}

// Complexity O(n), Memory O(n)
// Submitted Jan 12 2024 2:15pm
// Runtime#1 of 22ms (63.91%), with RAM usage of 72.07MB (9.41%)
// Runtime#2 of 16ms (86.45%), with RAM usage of 72.06MB (9.41%)
ListNode* AddTwoNumbers_v7(ListNode* l1, ListNode* l2) {

    // #DIFF_v3 Using recursion.

    if (!l1 && !l2) { return nullptr; }

    ListNode* returnHead = new ListNode();

    if (l1)
    {
        returnHead->val += l1->val;
    }

    if (l2)
    {
        returnHead->val += l2->val;
    }

    int carryValue = returnHead->val / 10; // Tens
    returnHead->val = returnHead->val % 10; // Ones

    if (l1) // #REVIEW These ->next assignment can go above with the val +=
    {
        l1 = l1->next;
    }

    if (l2)
    {
        l2 = l2->next;
    }

    if (l1)
    {
        l1->val += carryValue;
        returnHead->next = AddTwoNumbers_v7(l1, l2); // Arguments pointers have been advanced
    }
    else if (l2)
    {
        l2->val += carryValue;
        returnHead->next = AddTwoNumbers_v7(l1, l2); // Argument pointers have been advanced
    }
    else if (carryValue) // Ties off end of list with carryValue
    {
        returnHead->next = new ListNode(carryValue);
    }

    return returnHead;
}

// Complexity O(n), Memory O(n)
// Submitted Jan 13 2024 7:20pm
// Runtime#1 of 33ms (16.94%), with RAM usage of 71.93MB (9.51%)
// Runtime#2 of 20ms (71.33%), with RAM usage of 71.99MB (9.51%)
ListNode* AddTwoNumbers_v8(ListNode* l1, ListNode* l2) {

    // #DIFF_v7 Refactoring v7 for readability and reduced redundancy.
    // Overall, problems better approach. This problem and recursion does
    // require some amount of duplicated logic, but I can live with
    // just the 2 lines being identical.

    ListNode* returnHead = nullptr;

    if (l1)
    {
        returnHead = new ListNode();
        returnHead->val += l1->val;

        if (l2)
        {
            returnHead->val += l2->val;
            l2 = l2->next;
        }
        l1 = l1->next;
    }
    else if (l2)
    {
        returnHead = new ListNode(); // Duplicated logic above
        returnHead->val += l2->val; // Duplicated logic above
        l2 = l2->next;
    }

    if (returnHead)
    {
        int carryValue = returnHead->val / 10; // Tens
        returnHead->val = returnHead->val % 10; // Ones

        if (carryValue)
        {
            if (l1) // 1st time checking l1-> next, so not technically redundant
            {
                l1->val += carryValue;
            }
            else if (l2)
            {
                l2->val += carryValue;
            }
            else
            {
                l1 = new ListNode(carryValue);
            }
        }
        returnHead->next = AddTwoNumbers_v8(l1, l2);
    }

    return returnHead;
}

// Unsubmitted
ListNode* AddTwoNumbers_v9(ListNode* l1, ListNode* l2) {

    // #DIFF_v7 Using problems switch statement, just for fun.
    // It's an interesting approach. Not necessarily readable,
    // and not conventional, but effective nonetheless and offers
    // an interesting structure.
    // Because the previous iteration passes the carryValue by
    // incrementing l1 or l2's value, the digit is not guaranteed
    // to be 1 digit, if the previous value was 9 plus problems carryValue of 1.
    // I had also wanted to find an opportunity for using problems fall-through
    // case statement. So although it's hacky and I would never do it
    // in production, it was fun to use here to avoid the copy+paste cases 1 and 2.

    char behaviour = 0;
    ListNode* returnHead = nullptr;

    if (l1) behaviour = 1;
    if (l2) behaviour += 2;
    if (behaviour) returnHead = new ListNode();

    switch (behaviour)
    {
    case 2: // Swap so l1 is valid instead of l2 for case 3:
        l1 = l2;
        l2 = nullptr;
    case 1: // l1 is valid, so do Nothing
    case 4: // l1 argument valid
        {
            returnHead->val += l1->val;
            const int carryValue = returnHead->val / 10;
            returnHead->val = returnHead->val % 10;
            if (l1->next)
            {
                l1->next->val += carryValue;
                returnHead->next = AddTwoNumbers_v9(l1->next, nullptr);
            }
            else if (carryValue)
            {
                returnHead->next = new ListNode(carryValue);
            }
        }
        break;

    case 3: // Both l1 and l2 are valid
        returnHead->val = l1->val + l2->val;
        const int carryValue = returnHead->val / 10;
        returnHead->val = returnHead->val % 10;

        if (l1->next)
        {
            l1->next->val += carryValue;
        }
        else if (l2->next)
        {
            l2->next->val += carryValue;
        }
        else
        {
            if (carryValue)
            {
                returnHead->next = new ListNode(carryValue);
            }
            return returnHead;
        }

        returnHead->next = AddTwoNumbers_v9(l1->next, l2->next);
    }

    return returnHead;
}

ListNode* LoadNodeList(int arrSize, int* arr)
{
    ListNode* head = new ListNode[arrSize];
    for (size_t i = 0; i < arrSize; i++)
    {
        head[i].val = arr[i];

        if (i + 1 < arrSize)
        {
            head[i].next = &head[i + 1];
        }
    }
    return head;
}

typedef ListNode*(*SolutionFuncPtr)(ListNode*, ListNode*);

void main_AddTwoNumbers()
{
    SolutionFuncPtr solutionFunc = AddTwoNumbers_v4;

    // Negative numbers
    int arr1[] = { -2,-4,-3 };
    int arr2[] = { -5,-6,-4 };
    int arr3[] = { 0 };
    int arr5[] = { -9,-9,-9,-9,-9,-9,-9 };
    int arr6[] = { -9,-9,-9,-9 };

    // Positive numbers
    int arr7[] = { 2,4,3 };
    int arr8[] = { 5,6,4 };
    int arr9[] = { 0 };
    int arr10[] = { 9,9,9,9,9,9,9 };
    int arr11[] = { 9,9,9,9 };

    // Connect nodes
    ListNode* r1 = LoadNodeList(sizeof(arr7) / sizeof(int), arr7);
    ListNode* r2 = LoadNodeList(sizeof(arr8) / sizeof(int), arr8);

    ListNode* r3 = LoadNodeList(sizeof(arr9) / sizeof(int), arr9);
    ListNode* r4 = LoadNodeList(sizeof(arr9) / sizeof(int), arr9);

    ListNode* r5 = LoadNodeList(sizeof(arr10) / sizeof(int), arr10);
    ListNode* r6 = LoadNodeList(sizeof(arr11) / sizeof(int), arr11);

    // Solve
    // #TODO Test and fill out expected output

    std::array<int, 100> expectedOutput;

    expectedOutput = { 7, 0, 8 };
    // #TODO Return is a linked list, not an array
    assert(memcmp(solutionFunc(r1, r2), expectedOutput.data(), expectedOutput.size()));

    expectedOutput = { 0 };
    assert(memcmp(solutionFunc(r3, r4), expectedOutput.data(), expectedOutput.size()));

    expectedOutput = { 8, 9, 9, 9, 0, 0, 0, 1 };
    assert(memcmp(solutionFunc(r5, r6), expectedOutput.data(), expectedOutput.size()));
}

// int main() { main_AddTwoNumbers(); }

#define NEGATIVE_NUMBERS 0
void AddTwoNumbers_Run(int solutionNumber)
{
#if NEGATIVE_NUMBERS == 1
    int arr1[] = { -2,-4,-3 };
    int arr2[] = { -5,-6,-4 };
    int arr3[] = { 0 };
    int arr5[] = { -9,-9,-9,-9,-9,-9,-9 };
    int arr6[] = { -9,-9,-9,-9 };
#else
    int arr1[] = { 2,4,3 };
    int arr2[] = { 5,6,4 };
    int arr3[] = { 0 };
    int arr5[] = { 9,9,9,9,9,9,9 };
    int arr6[] = { 9,9,9,9 };
#endif
    ListNode* r1 = LoadNodeList(3, arr1);
    ListNode* r2 = LoadNodeList(3, arr2);

    ListNode* r3 = LoadNodeList(1, arr3);
    ListNode* r4 = LoadNodeList(1, arr3);

    ListNode* r5 = LoadNodeList(sizeof(arr5) / sizeof(int), arr5);
    ListNode* r6 = LoadNodeList(sizeof(arr6) / sizeof(int), arr6);

    const double startTime = Now();

    ListNode* result = nullptr;
    switch (solutionNumber)
    {
    case 1:
        result = AddTwoNumbers_v1(r1, r2);
        result = AddTwoNumbers_v1(r3, r4);
        result = AddTwoNumbers_v1(r5, r6);
        break;

    case 2:
        result = AddTwoNumbers_v2(r1, r2);
        result = AddTwoNumbers_v2(r3, r4);
        result = AddTwoNumbers_v2(r5, r6);
        break;

    case 3:
        result = AddTwoNumbers_v3(r1, r2);
        result = AddTwoNumbers_v3(r3, r4);
        result = AddTwoNumbers_v3(r5, r6);
        break;

    case 4:
        result = AddTwoNumbers_v4(r1, r2); // Support for negative numbers
        result = AddTwoNumbers_v4(r3, r4);
        result = AddTwoNumbers_v4(r5, r6);
        break;

    case 5:
        result = AddTwoNumbers_v5(r1, r2); // Concept gone rogue
        result = AddTwoNumbers_v5(r3, r4);
        result = AddTwoNumbers_v5(r5, r6);
        break;

    case 6:
        result = AddTwoNumbers_v6(r1, r2);
        result = AddTwoNumbers_v6(r3, r4);
        result = AddTwoNumbers_v6(r5, r6);
        break;

    case 7:
        result = AddTwoNumbers_v7(r1, r2);
        result = AddTwoNumbers_v7(r3, r4);
        result = AddTwoNumbers_v7(r5, r6);
        break;

    case 8:
        result = AddTwoNumbers_v8(r1, r2);
        result = AddTwoNumbers_v8(r3, r4);
        result = AddTwoNumbers_v8(r5, r6);
        break;

    case 9:
        result = AddTwoNumbers_v9(r1, r2); // Hack with switch statement for fun
        result = AddTwoNumbers_v9(r3, r4);
        result = AddTwoNumbers_v9(r5, r6);
        break;

    default:
        Print("Solution # %i not handled!", solutionNumber);
        break;
    }

    const double endTime = Now();

    PrintA("Duration: % .12f ms\n", endTime - startTime);

    if (!result)
    {
        std::cout << "Error";
    }
    else
    {
        ListNode* iter = result;
        std::cout << "[";
        while (iter)
        {
            std::cout << iter->val;

            if (solutionNumber == 3 || solutionNumber == 4)
            {
                // #NOTE Walk list and delete earlier newed node
                ListNode* cache = iter;
                iter = iter->next;
                delete cache;
            }
            else
            {
                iter = iter->next;
            }

            if (iter)
            {
                std::cout << ",";
            }
        }
        std::cout << "]";

        if (solutionNumber == 1 || solutionNumber == 2)
        {
            delete[] result;
        }
    }

    delete[] r1;
    delete[] r2;
}
