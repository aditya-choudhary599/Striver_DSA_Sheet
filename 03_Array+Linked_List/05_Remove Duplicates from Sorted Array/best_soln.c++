// Question Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// TC : 0(N)
// SC : 0(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int insert_index = -1;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int curr = nums[i];
            i += 1;
            while (i < n && nums[i] == nums[i - 1])
            {
                i += 1;
            }

            insert_index += 1;
            nums[insert_index] = curr;
        }

        // we have to return the number of unique elements
        return insert_index + 1;
    }
};