#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        unsigned long int shift_sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            shift_sum += shifts[i];
            s[i] = char((int(s[i]) - int('a') + shift_sum) % 26 + int('a'));
        }

        return s;
    }
};

int main() {
    
    Solution s = Solution();

    string st = "abc";
    vector shifts = {1,1,1};  
    cout<<s.shiftingLetters(st, shifts); // output must be ddd

}