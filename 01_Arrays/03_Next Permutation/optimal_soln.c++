/* // Question link : https://leetcode.com/problems/next-permutation/description/

// This solution is inspired from the optimal approach idea that striver gave in his solution video of this question
// The link for that video is : https://www.youtube.com/watch?v=JDOXKqF60RQ&t=808s */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This checks whether the given nums is already sorted in the descending order
    bool helper(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 1)
        {
            if (nums[i] < nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (helper(nums) == true)
        {
            // this means the given nums sequence is already sorted in descending order.
            // So the answer will be the given sequence in the sorted in ascending order.
            // This is one of edge case handled over here.
            sort(nums.begin(), nums.end());
            return;
        }

        vector<int> temp;
        for (int i = n - 1; i >= 0; i -= 1)
        {
            temp.insert(temp.begin(), nums[i]);
            if (helper(temp) == true)
            {
                // We cannot do anything in this case
                continue;
            }
            else
            {
                vector<int> ans;
                // now first handling the suffix part
                priority_queue<int, vector<int>, greater<int>> pq;
                int temp_size = n - i;
                for (int j = 0; j < temp_size; j += 1)
                {
                    pq.push(temp[j]);
                }
                bool found = false;
                while (pq.empty() != true)
                {
                    if (pq.top() > temp[0] && found == false)
                    {
                        ans.insert(ans.begin(), pq.top());
                        pq.pop();
                        found = true;
                        continue;
                    }
                    else
                    {
                        ans.push_back(pq.top());
                        pq.pop();
                    }
                }

                // Now lets handle the prefix part
                vector<int> prefix;
                prefix.insert(prefix.end(), nums.begin(), nums.begin() + i);
                prefix.insert(prefix.end(), ans.begin(), ans.end());

                nums = prefix;
                return;
            }
        }
        return;
    }
};
