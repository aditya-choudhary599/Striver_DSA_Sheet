// Question Link : https://leetcode.com/problems/reverse-pairs/

// This solution is based on whatever striver taught as a part of his optimal approach for this question.

// THIS QUESTION IS NOT SOLVABLE BY THE TECHNIQUE THAT WE APPLIED FOR THE COUNT INVERSIONS QUESTION

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
public:
    void g(int start_1, int end_1, int start_2, int end_2, vector<int> &nums, int &ans)
    {
        int size_1 = (end_1 - start_1) + 1;
        int size_2 = (end_2 - start_2) + 1;

        vector<ll> temp_1(size_1), temp_2(size_2);

        for (int i = start_1; i <= end_1; i += 1)
        {
            temp_1[i - start_1] = ll(nums[i]);
        }

        for (int i = start_2; i <= end_2; i += 1)
        {
            temp_2[i - start_2] = ll(nums[i]);
        }

        // Step for our ans
        int j = 0;
        for (int i = 0; i < size_1; i += 1)
        {
            while (j < size_2 && temp_1[i] > 2 * temp_2[j])
            {
                j += 1;
            }
            ans = ans + j;
        }

        // Now merged the two sorted arrays
        int i = 0, insert_index = start_1;
        j = 0;

        while (i < size_1 && j < size_2)
        {
            if (temp_1[i] <= temp_2[j])
            {
                nums[insert_index] = temp_1[i];
                i += 1;
                insert_index += 1;
            }
            else
            {
                nums[insert_index] = temp_2[j];
                j += 1;
                insert_index += 1;
            }
        }

        while (i < size_1)
        {
            nums[insert_index] = temp_1[i];
            i += 1;
            insert_index += 1;
        }

        while (j < size_2)
        {
            nums[insert_index] = temp_2[j];
            j += 1;
            insert_index += 1;
        }

        return;
    }

    void f(int start, int end, vector<int> &nums, int &ans)
    {
        if (start >= end)
        {
            return;
        }
        int mid = start + (end - start) / 2;
        f(start, mid, nums, ans);
        f(mid + 1, end, nums, ans);
        g(start, mid, mid + 1, end, nums, ans);
        return;
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        f(0, n - 1, nums, ans);
        return ans;
    }
};