// Question Link : https://leetcode.com/problems/find-the-duplicate-number/

// TC : 0(N)
// SC : 0(1)

// The method used in this problem is Floyd warshal cycle detection method used for detecting cycles in the linked list

// The speciality of this solution is the constant space complexity

// Their are many other methods to approach this solution with linear time complexity but none of them can have the constant space complexity

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};