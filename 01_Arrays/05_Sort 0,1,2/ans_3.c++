// Question Link : https://leetcode.com/problems/sort-colors/description/

// TC : 0(N)
// SC : 0(1)

// Dutch National Flag Algorithm Implemenation which striver taught in his video. This is the best possible soln for this problem.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low += 1;
                mid += 1;
            }
            else if (nums[mid] == 2)
            {

                swap(nums[high], nums[mid]);
                high -= 1;
            }
            else
            {
                mid += 1;
            }
        }
        return;
    }
};