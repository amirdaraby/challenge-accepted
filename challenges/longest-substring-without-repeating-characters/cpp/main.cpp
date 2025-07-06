#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int startIndex = 0;

        unordered_map<char, int> characters;

        int longest = 0;

        for (int i = 0; i < s.length(); i++)
        {
            unordered_map<char, int>::iterator mapResult = characters.find(s[i]);

            if (mapResult != characters.end())
            {
                if (mapResult->second >= startIndex)
                    startIndex = mapResult->second + 1;

                characters[s[i]] = i;
            }
            else
            {
                characters.insert({s[i], i});
            }

            longest = max(longest, i - startIndex + 1);
        }

        return longest;
    }
};

int main()
{

    Solution s = Solution();

    cout << s.lengthOfLongestSubstring("abaaabcabc"); // 3

    return 0;
}