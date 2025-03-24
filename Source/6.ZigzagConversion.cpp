
#include <assert.h>
#include <string>
#include <vector>

// Link to leetcode problem https://leetcode.com/problems/zigzag-conversion/

// Submitted 16/03/25 12:08pm
// Runtime of 0ms (100%), with RAM usage of 10.58MB (99.27%)
std::string ZigzagConversion_v1(const std::string s, const int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    std::string returnValue(s);
    returnValue.clear();

    for (size_t row = 0; row < numRows; row++)
    {
        const int stepSize = 2 * (numRows - 1);

        for (size_t counter = row; counter < s.size(); counter += stepSize)
        {
            returnValue.push_back(s[counter]);

            const int index = counter + stepSize - (2 * row);
            if (row > 0 && row < numRows - 1 &&
                index < s.size())
            {
                returnValue.push_back(s[index]);
            }
        }
    }

    return returnValue;
}

// Submitted 16/03/25 12:27pm
// Runtime of 4ms (64.48%), with RAM usage of 14MB (58.48%)
std::string ZigzagConversion_v2(const std::string s, const int numRows)
{
    // #NOTE From https://neetcode.io/solutions/zigzag-conversion

    if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    std::vector<std::string> res(numRows);
    int row = 0, dir = 1;

    for (const char& c : s) {
        res[row] += c;
        row += dir;
        if (row == 0 || row == numRows - 1) {
            dir *= -1;
        }
    }

    std::string result;
    for (std::string& rowString : res) {
        result += rowString;
    }
    return result;
}

void main_ZigzagConverion()
{
    std::string result;
    result.reserve(100);

    result = ZigzagConversion_v1("PAYPALISHIRING", 3);
    assert(!strcmp(result.c_str(), "PAHNAPLSIIGYIR"));

    result = ZigzagConversion_v1("ZIGZAG", 3);
    assert(!strcmp(result.c_str(), "ZAIZGG"));

    result = ZigzagConversion_v1("PAYPALISHIRING", 4);
    assert(!strcmp(result.c_str(), "PINALSIGYAHRPI"));

    result = ZigzagConversion_v1("SNAKESNAKESNAKE", 4);
    assert(!strcmp(result.c_str(), "SNANSANKAEKSEKE"));

    result = ZigzagConversion_v1("PAYPALISHIRING", 5);
    assert(!strcmp(result.c_str(), "PHASIYIRPLIGAN"));

    // V2
    result = ZigzagConversion_v2("PAYPALISHIRING", 3);
    assert(!strcmp(result.c_str(), "PAHNAPLSIIGYIR"));

    result = ZigzagConversion_v2("ZIGZAG", 3);
    assert(!strcmp(result.c_str(), "ZAIZGG"));

    result = ZigzagConversion_v2("PAYPALISHIRING", 4);
    assert(!strcmp(result.c_str(), "PINALSIGYAHRPI"));

    result = ZigzagConversion_v2("SNAKESNAKESNAKE", 4);
    assert(!strcmp(result.c_str(), "SNANSANKAEKSEKE"));

    result = ZigzagConversion_v2("PAYPALISHIRING", 5);
    assert(!strcmp(result.c_str(), "PHASIYIRPLIGAN"));
}