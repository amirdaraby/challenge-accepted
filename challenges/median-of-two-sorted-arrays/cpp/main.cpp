#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &firstArray, vector<int> &secondArray)
    {
        double median = 0;

        vector<int> merged;
        merged.resize(firstArray.size() + secondArray.size());

        merge(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), merged.begin());

        int size = merged.size();

        if (size % 2 == 1) // odd
        {
            median = merged[size / 2];
        }
        else
        { // even
            median = (merged[size / 2] + merged[size / 2 - 1]) / 2.0;
        }

        return median;
    }
};


int main()
{
    Solution s;

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double median = s.findMedianSortedArrays(nums1, nums2); // 2.5

    cout << median;

    return 0;
}