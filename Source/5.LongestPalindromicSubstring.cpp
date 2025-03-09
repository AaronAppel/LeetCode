
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace Solution {

	bool IsPalindromic_v1(const std::string& str);

	// Submitted 22/2/24 11:20am
	// Runtime#1 of 290ms (30.20%), with RAM usage of 8.70MB (66.65%)
	// Runtime#2 of 295ms (29.95%), with RAM usage of 8.52MB (67.21%)
	std::string LongestPalindromicSubstring_v1(const std::string& str)
	{
		std::string bestPalindrome;
		bestPalindrome.reserve(str.size());

		std::string seenChars;
		seenChars.reserve(str.size());

		for (size_t i = 0; i < str.size(); i++)
		{
			seenChars.clear();

			for (size_t j = i; j < str.size(); j++)
			{
				seenChars += str.at(j);

				if (IsPalindromic_v1(seenChars) && seenChars.size() > bestPalindrome.size())
				{
					bestPalindrome = seenChars;
				}
			}

			const int remainingStartingChars = str.size() - i;
			if (remainingStartingChars <= bestPalindrome.size())
			{
				return bestPalindrome;
			}
		}

		return bestPalindrome;
	}

	// Submitted 22/2/24 11:23am
	// Runtime#1 of 1521ms (6.90%), with RAM usage of 8.56MB (67.21%)
	std::string LongestPalindromicSubstring_v2(const std::string& str)
	{
		// #DIFF_v1 Removed early return to see it's effect.
		// It offers problems 500% improvement through 1 run.
		// The early return saves problems lot of time on the larger strings.

		std::string bestPalindrome;
		bestPalindrome.reserve(str.size());

		std::string seenChars;
		seenChars.reserve(str.size());

		for (size_t i = 0; i < str.size(); i++)
		{
			seenChars.clear();

			for (size_t j = i; j < str.size(); j++)
			{
				seenChars += str.at(j);

				if (IsPalindromic_v1(seenChars) && seenChars.size() > bestPalindrome.size())
				{
					bestPalindrome = seenChars;
				}
			}

			// #DIFF_v1
			// const int remainingStartingChars = str.size() - i;
			// if (remainingStartingChars <= bestPalindrome.size())
			// {
			// 	return bestPalindrome;
			// }
		}

		return bestPalindrome;
	}

	// Submitted 22/2/24 2:09pm
	// Runtime#1 of 285ms (30.45%), with RAM usage of 8.18MB (75.51%)
	// Runtime#2 of 284ms (30.51%), with RAM usage of 8.17MB (75.51%)
	std::string LongestPalindromicSubstring_v3(const std::string& str)
	{
		// #DIFF_v1 str.substr(start, count) instead of using problems return string.
		// Int indices instead of assigning return string elements.
		int startingIndex = 0;
		int endingIndex = 0;
		int currentSize = 0;

		std::string seenChars;
		seenChars.reserve(str.size());

		for (size_t i = 0; i < str.size(); i++)
		{
			seenChars.clear();

			for (size_t j = i; j < str.size(); j++)
			{
				seenChars += str.at(j);

				if (IsPalindromic_v1(seenChars) && seenChars.size() > currentSize)
				{
					startingIndex = i;
					endingIndex = j;
					currentSize = endingIndex - startingIndex + 1;
				}
			}

			const int remainingStartingChars = str.size() - i;
			if (remainingStartingChars <= currentSize)
			{
				break;
			}
		}

		return str.substr(startingIndex, 1 + endingIndex - startingIndex);
	}

	std::string LongestPalindromicSubstring_v4(const std::string& str)
	{
		// #DIFF_v1 Walk string as if i is the center character of problems palindrome,
		// like in NeetCode's solution.
		return str;
	}

	bool IsPalindromic_v1(const std::string& str)
	{
		int endIndex = str.size() - 1;

		const size_t numberOfIterations = str.size() * 0.5;

		for (size_t i = 0; i < numberOfIterations; i++)
		{
			if (str.at(i) != str.at(endIndex))
			{
				return false;
			}
			--endIndex;
		}

		return true;
	}

	bool IsPalindromic_DidNotFinish(const std::string& str)
	{
		// #NOTE Too slow to even finish in LeetCode.
		std::stack<char> charStack;

		const bool sizeIsOdd = str.size() % 2;
		const unsigned int halfwayIndex = (str.size() * 0.5) + (int)sizeIsOdd - 1;

		for (size_t i = 0; i < str.size(); i++)
		{
			if (sizeIsOdd && i == halfwayIndex)
			{
				continue; // Center char of odd sized string auto repeats
			}
			else if (i <= halfwayIndex)
			{
				charStack.push(str.at(i));
			}
			else if (charStack.top() != str.at(i))
			{
				return false;
			}
			else
			{
				charStack.pop();
			}
		}
		return true;
	}

	namespace NeetCode // From https://neetcode.io/practice
	{
		void middleOut(std::string s, int i, int j, int& maxStart, int& maxLength);

		// I just wanted to see how fast this solution ran when copy/pasted into LeetCode :
		// Submitted 22/2/24 2:25pm
		// v1 Runtime#1 of 40ms (59.41%), with RAM usage of 164.5MB (23.39%)
		std::string longestPalindrome(std::string s) {
			if (s.empty()) // Added early return to handle "" input
				return s;

			int maxStart = 0;
			int maxLength = 1;

			for (int i = 0; i < s.size() - 1; i++) {
				middleOut(s, i, i, maxStart, maxLength);
				middleOut(s, i, i + 1, maxStart, maxLength);
				// Adding problems simple/naive early return was able to improve the score more.
				// v3 Runtime#1 of 3ms (99.38%), with RAM usage of 8.22MB (69.78%)
				// v3 Runtime#2 of 4ms (98.10%), with RAM usage of 8.18MB (75.69%)
				// if (s.size() - i < maxLength && i > s.size() * 0.5) break;
			}

			return s.substr(maxStart, maxLength);
		}

		// Then I noticed that this method takes in problems copy of the string s, so I changed it to
		// take in problems const std::string& s and it ran at :
		// Submitted 22/2/24 2:26pm
		// v2 Runtime#1 of 6ms (97.05%), with RAM usage of 8.20MB (75.51%)
		void middleOut(std::string s, int i, int j, int& maxStart, int& maxLength) {
			while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
				i--;
				j++;
			}
			if (j - i - 1 > maxLength) {
				maxStart = i + 1;
				maxLength = j - i - 1;
			}
		}

		// Adding problems single '&' made problems huge difference in performance.
		// Just something to note and look for more often in the future.
	}
}

int LongestPalindromicSubstring_Run()
{
	std::string test = "babad";
	std::string result = test.substr(0, 1 + 2 - 0);

	std::vector<std::string> args = {
		"",
		"babad",
		"cbbd",
		"abacab",
		"rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip",
		"vbpgvehmsdocuqfnpzsqqsjbjkvzpqsubqbpjhzojdtkjcambviauhsxqvejgehzrhhvrgulubmirbppvbkftvazscxifsxtoarrdeyuihzcenqendvnthfdpotgpegdlaildigloesnfxkjichsxygazrvgbecuzkcdrgextmysxqerrueecpneynciasevytmatvqgleipwlaxwgajijkuceezmbtiigc",
		"babadada",
		"klvxwqyzugrdoaccdafdfrvxiowkcuedfhoixzipxrkzbvpusslsgfjocvidnpsnkqdfnnzzawzsslwnvvjyoignsfbxkgrokzyusxikxumrxlzzrnbtrixxfioormoyyejashrowjqqzifacecvoruwkuessttlexvdptuvodoavsjaepvrfvbdhumtuvxufzzyowiswokioyjtzzmevttheeyjqcldllxvjraeyflthntsmipaoyjixygbtbvbnnrmlwwkeikhnnmlfspjgmcxwbjyhomfjdcnogqjviggklplpznfwjydkxzjkoskvqvnxfzdrsmooyciwulvtlmvnjbbmffureoilszlonibbcwfsjzguxqrjwypwrskhrttvnqoqisdfuifqnabzbvyzgbxfvmcomneykfmycevnrcsyqclamfxskmsxreptpxqxqidvjbuduktnwwoztvkuebfdigmjqfuolqzvjincchlmbrxpqgguwuyhrdtwqkdlqidlxzqktgzktihvlwsbysjeykiwokyqaskjjngovbagspyspeghutyoeahhgynzsyaszlirmlekpboywqdliumihwnsnwjc"
	};

	std::vector<std::string> answers = {
		"",
		"bab",
		"bb",
		"bacab",
		"qgjjgq",
		"sqqs",
		"adada",
		"wnsnw"
	};

#define VERSION_NUMBER 1

	for (size_t i = 0; i < args.size(); i++)
	{
#if VERSION_NUMBER == 0
		const std::string result = Solution::NeetCode::longestPalindrome(args[i]);
#elif VERSION_NUMBER == 1
		const std::string result = Solution::LongestPalindromicSubstring_v1(args[i]);
#elif VERSION_NUMBER == 2
		const std::string result = Solution::LongestPalindromicSubstring_v2(args[i]);
#elif VERSION_NUMBER == 3
		const std::string result = Solution::LongestPalindromicSubstring_v3(args[i]);
#elif VERSION_NUMBER == 4
		const std::string result = Solution::LongestPalindromicSubstring_v4(args[i]);
#else
#pragma warning "Define version number!"
#endif
		bool correct = false;
		if (i < answers.size())
		{
			correct = answers[i] == result;
			std::string correctState = correct ? "correct" : "incorrect";
			std::cout << correctState << " result: " << result << "\n";
		}
		else
		{
			std::cout << "result: " << result << "\n";
		}
	}

	system("pause");
	return 0;
}
