#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int startIndex = 0;
        int characters[128];

        fill(characters, characters + 128, -1);

        int longest = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if (characters[c] != -1 && characters[c] >= startIndex)
            {
                startIndex = characters[c] + 1;
            }

            characters[c] = i;

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