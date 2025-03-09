
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace Solution
{
	// Submitted 18/01/24 4:15pm
	// Runtime#1 of 75ms (10.39%), with RAM usage of 7.26MB (94.82%)
	// Runtime#2 of 67ms (11.26%), with RAM usage of 7.48MB (90.74%)
	int lengthOfLongestSubstring_v1(std::string s) {

		if (s.empty()) return 0;

		std::string currentSubString;
		currentSubString.reserve(5);

		int lengthOfLongestSubString = 1;
		int lastSavedIndex = 1;
		for (size_t i = 0; i < s.size();) // i++) // Iterate using if/else logic below
		{
			currentSubString += s[i];

			int safeNextIndex = i + 1;
			if (safeNextIndex >= s.size())
			{
				safeNextIndex = i;
			}

			if (currentSubString.find(s[safeNextIndex]) != std::string::npos)
			{
				if (currentSubString.length() > lengthOfLongestSubString)
				{
					lengthOfLongestSubString = currentSubString.length();
				}
				currentSubString = "";
				i = lastSavedIndex++;
			}
			else
			{
				i++;
			}
		}

		return lengthOfLongestSubString;
	}

	// Submitted 19/01/24 11:37am
	// Runtime#1 of 50ms (13.23%), with RAM usage of 11.66MB (14.58%)
	// Runtime#2 of 39ms (15.15%), with RAM usage of 11.42MB (16.35%)
	int lengthOfLongestSubstring_v2(std::string s) {

		// #DIFF_v1 Use problems map to store occurrences of checked chars with their index to
		// avoid using an index iteration that could drastically increase complexity.
		// RAM vs CPU tradeoff.
		// .clear() string instead of assigning "".

		// #REVIEW Faster but messy. The edge cases are more difficult to handle with
		// this solution. Next I hope to review the loop and conditions closer.

		if (s.empty()) return 0;

		std::map<char, int8_t> seenCharacterIndices;

		std::string currentSubString;
		currentSubString.reserve(5);

		int lengthOfLongestSubString = 1;
		for (size_t i = 0; i < s.size();) // i++) // Iterate using if/else logic below
		{
			auto it = seenCharacterIndices.find(s[i]);
			if (it == seenCharacterIndices.end())
			{
				seenCharacterIndices.insert({ s[i], i });
			}

			currentSubString += s[i];

			int safeNextIndex = i + 1;
			if (safeNextIndex >= s.size()) // #TODO Try to remove the safe if check in future iterations
			{
				safeNextIndex = i;
			}

			if (currentSubString.find(s[safeNextIndex]) != std::string::npos)
			{
				if (currentSubString.length() > lengthOfLongestSubString)
				{
					lengthOfLongestSubString = currentSubString.length();
				}

				i = seenCharacterIndices[s[safeNextIndex]] + 1;

				if (it != seenCharacterIndices.end())
				{
					it->second = i;// +1;
				}

				currentSubString.clear();
			}
			else
			{
				if (it != seenCharacterIndices.end())
				{
					it->second = i;
				}
				i++;
			}
		}

		return lengthOfLongestSubString;
	}

	// Submitted 19/01/24 2:12pm
	// Runtime#1 360ms (6.90%), with RAM usage of 9.14MB (49.08%)
	// Runtime#2 363ms (6.89%), with RAM usage of 9.00MB (51.95%)
	int lengthOfLongestSubstring_v3(const std::string s) {

		// #DIFF_v2 Avoid 1st iteration.
		// Search string manually.
		// Const argument.
		// Avoid future iterations. #TODO

		if (s.empty()) { return 0; }

		int const startingStringSize = 20;
		std::string currentSubString;
		currentSubString.reserve(startingStringSize);
		currentSubString += s[0];

		int returnLongestStringLength = 1;

		for (size_t i = 1; i < s.size(); i++)
		{
			int index = -1;
			for (size_t j = 0; j < currentSubString.size(); j++)
			{
				if (currentSubString[j] == s[i])
				{
					index = j;
					break;
				}
			}

			if (index >= 0)
			{
				if (currentSubString.length() > returnLongestStringLength)
				{
					returnLongestStringLength = currentSubString.length();
				}
				i = i - currentSubString.size() + index + 1;

				currentSubString.clear();
			}
			currentSubString += s[i];
		}

		// #TODO Ensure final character pass, or Handle not checking currentSubString.size() at end of array s
		if (currentSubString.length() > returnLongestStringLength)
		{
			returnLongestStringLength = currentSubString.length();
		}

		return returnLongestStringLength;
	}

	// Submitted 19/01/24 2:19pm
	// 62ms (11.74%), with RAM usage of 9.14MB (49.08%)
	// 62ms (11.74%), with RAM usage of 9.07MB (49.90%)
	int lengthOfLongestSubstring_v4(const std::string s) {

		// #DIFF_v3 Using find_first_of().

		if (s.empty()) { return 0; }

		int const startingStringSize = 20;
		std::string currentSubString;
		currentSubString.reserve(startingStringSize);
		currentSubString += s[0];

		int returnLongestStringLength = 1;

		for (size_t i = 1; i < s.size(); i++)
		{
			size_t index = currentSubString.find_first_of(s[i]);

			if (index != std::string::npos)
			{
				if (currentSubString.length() > returnLongestStringLength)
				{
					returnLongestStringLength = currentSubString.length();
				}
				i = i - currentSubString.size() + index + 1;

				currentSubString.clear();
			}
			currentSubString += s[i];
		}

		// Ensure final character pass, i.e. Handle not checking currentSubString.size() at end of array s
		if (currentSubString.length() > returnLongestStringLength)
		{
			returnLongestStringLength = currentSubString.length();
		}

		return returnLongestStringLength;
	}

	// Submitted 19/01/24 2:40pm
	// 60ms (11.96%), with RAM usage of 9.12MB (49.22%)
	// 57ms (12.33%), with RAM usage of 9.15MB (49.22%)
	// 61ms (11.83%), with RAM usage of 9.05MB (50.03%) <- startingStringSize=3
	int lengthOfLongestSubstring_v5(const std::string s) {

		// #DIFF_v4 Avoid future iterations with an early return.

		if (s.empty()) { return 0; }

		int const startingStringSize = 20;
		std::string currentSubString;
		currentSubString.reserve(startingStringSize);
		currentSubString += s[0];

		int returnLongestStringLength = 1;

		for (size_t i = 1; i < s.size(); i++)
		{
			size_t index = currentSubString.find_first_of(s[i]);

			if (index != std::string::npos)
			{
				if (currentSubString.length() > returnLongestStringLength)
				{
					returnLongestStringLength = currentSubString.length();
				}

				i = i - currentSubString.size() + index + 1;
				if (s.size() - i <= returnLongestStringLength)
				{
					return returnLongestStringLength;
				}


				currentSubString.clear();
			}
			currentSubString += s[i];
		}

		if (currentSubString.length() > returnLongestStringLength)
		{
			returnLongestStringLength = currentSubString.length();
		}

		return returnLongestStringLength;
	}

	// Unsubmitted
	int lengthOfLongestSubstring_v6(std::string s) {

		// #CONCEPT The s argument is mutable, and could be
		// used for optimization. One thought is to iterate over s from
		// back to front, and "pop" (resize the vector) once we have eliminated
		// end characters from consideration.
		// I don't find it useful to complete as version 5 seems sufficient, but it's
		// an option I considered along the way.
		return 0;
	}

	int lengthOfLongestSubstring_v7(std::string s) {

		// #DIFF Recursion

		// #TODO

		return 0;
	}
}

int AddTwoNumbers_Run()
{
	// _v1
#if 0
	{
		std::string arg1 = "abcabcbb";
		const int result1 = Solution::lengthOfLongestSubstring_v1(arg1);
		std::cout << result1 << "\n";

		std::string arg2 = "bbbbb";
		const int result2 = Solution::lengthOfLongestSubstring_v1(arg2);
		std::cout << result2 << "\n";

		std::string arg3 = "pwwkew";
		const int result3 = Solution::lengthOfLongestSubstring_v1(arg3);
		std::cout << result3 << "\n";

		std::string arg4 = " ";
		const int result4 = Solution::lengthOfLongestSubstring_v1(arg4);
		std::cout << result4 << "\n";

		std::string arg5 = "dvdf";
		const int result5 = Solution::lengthOfLongestSubstring_v1(arg5);
		std::cout << result5 << "\n";
	}
#endif
	// _v2
#if 0
	{
		std::string arg1 = "abcabcbb";
		const int result1 = Solution::lengthOfLongestSubstring_v2(arg1);
		std::cout << result1 << "\n";

		std::string arg2 = "bbbbb";
		const int result2 = Solution::lengthOfLongestSubstring_v2(arg2);
		std::cout << result2 << "\n";

		std::string arg3 = "pwwkew";
		const int result3 = Solution::lengthOfLongestSubstring_v2(arg3);
		std::cout << result3 << "\n";

		std::string arg4 = " ";
		const int result4 = Solution::lengthOfLongestSubstring_v2(arg4);
		std::cout << result4 << "\n";

		std::string arg5 = "dvdf";
		const int result5 = Solution::lengthOfLongestSubstring_v2(arg5);
		std::cout << result5 << "\n";

		std::string arg6 = "bbtablud";
		const int result6 = Solution::lengthOfLongestSubstring_v2(arg6);
		std::cout << result6 << "\n";

		std::string arg7 = "dtdztwhepnkguuuowsxztrmivgdyiw";
		const int result7 = Solution::lengthOfLongestSubstring_v2(arg7);
		std::cout << result7 << "\n";
	}
#endif
	// _v3
#if 0
	{
		std::string arg1 = "abcabcbb";
		const int result1 = Solution::lengthOfLongestSubstring_v3(arg1);
		std::cout << result1 << "\n";

		std::string arg2 = "bbbbb";
		const int result2 = Solution::lengthOfLongestSubstring_v3(arg2);
		std::cout << result2 << "\n";

		std::string arg3 = "pwwkew";
		const int result3 = Solution::lengthOfLongestSubstring_v3(arg3);
		std::cout << result3 << "\n";

		std::string arg4 = " ";
		const int result4 = Solution::lengthOfLongestSubstring_v3(arg4);
		std::cout << result4 << "\n";

		std::string arg5 = "dvdf";
		const int result5 = Solution::lengthOfLongestSubstring_v3(arg5);
		std::cout << result5 << "\n";

		std::string arg6 = "bbtablud";
		const int result6 = Solution::lengthOfLongestSubstring_v3(arg6);
		std::cout << result6 << "\n";

		std::string arg7 = "dtdztwhepnkguuuowsxztrmivgdyiw";
		const int result7 = Solution::lengthOfLongestSubstring_v3(arg7);
		std::cout << result7 << "\n";
	}
#endif
	// _v4
#if 0
	{
		std::string arg1 = "abcabcbb";
		const int result1 = Solution::lengthOfLongestSubstring_v4(arg1);
		std::cout << result1 << "\n";

		std::string arg2 = "bbbbb";
		const int result2 = Solution::lengthOfLongestSubstring_v4(arg2);
		std::cout << result2 << "\n";

		std::string arg3 = "pwwkew";
		const int result3 = Solution::lengthOfLongestSubstring_v4(arg3);
		std::cout << result3 << "\n";

		std::string arg4 = " ";
		const int result4 = Solution::lengthOfLongestSubstring_v4(arg4);
		std::cout << result4 << "\n";

		std::string arg5 = "dvdf";
		const int result5 = Solution::lengthOfLongestSubstring_v4(arg5);
		std::cout << result5 << "\n";

		std::string arg6 = "bbtablud";
		const int result6 = Solution::lengthOfLongestSubstring_v4(arg6);
		std::cout << result6 << "\n";

		std::string arg7 = "dtdztwhepnkguuuowsxztrmivgdyiw";
		const int result7 = Solution::lengthOfLongestSubstring_v4(arg7);
		std::cout << result7 << "\n";
	}
#endif
	// _v5
#if 1
	{
		std::string arg1 = "abcabcbb";
		const int result1 = Solution::lengthOfLongestSubstring_v5(arg1);
		std::cout << result1 << "\n";

		std::string arg2 = "bbbbb";
		const int result2 = Solution::lengthOfLongestSubstring_v5(arg2);
		std::cout << result2 << "\n";

		std::string arg3 = "pwwkew";
		const int result3 = Solution::lengthOfLongestSubstring_v5(arg3);
		std::cout << result3 << "\n";

		std::string arg4 = " ";
		const int result4 = Solution::lengthOfLongestSubstring_v5(arg4);
		std::cout << result4 << "\n";

		std::string arg5 = "dvdf";
		const int result5 = Solution::lengthOfLongestSubstring_v5(arg5);
		std::cout << result5 << "\n";

		std::string arg6 = "bbtablud";
		const int result6 = Solution::lengthOfLongestSubstring_v5(arg6);
		std::cout << result6 << "\n";

		std::string arg7 = "dtdztwhepnkguuuowsxztrmivgdyiw";
		const int result7 = Solution::lengthOfLongestSubstring_v5(arg7);
		std::cout << result7 << "\n";

		std::string arg8 = "anviaj";
		const int result8 = Solution::lengthOfLongestSubstring_v5(arg8);
		std::cout << result8 << "\n";
	}
#endif

	system("pause");
	return 0;
}