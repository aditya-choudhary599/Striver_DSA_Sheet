// Question Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    // This gives us the index of next-smaller element on the left .
    vector<int> nsl(vector<int> &arr, int n)
    {
        vector<int> ans;
        stack<int> st;
        int i = 0;
        while (i < n)
        {
            if (st.empty() == true)
            {
                ans.push_back(-1);
                st.push(i);
                i += 1;
                continue;
            }
            if (arr[st.top()] < arr[i])
            {
                ans.push_back(st.top());
                st.push(i);
                i += 1;
            }
            else
            {
                st.pop();
            }
        }
        return ans;
    }

    // This gives us the index of next-smaller element on the right .
    vector<int> nsr(vector<int> &arr, int n)
    {
        vector<int> ans;
        stack<int> st;
        int i = n - 1;
        while (i >= 0)
        {
            if (st.empty() == true)
            {
                ans.push_back(n);
                st.push(i);
                i -= 1;
                continue;
            }
            if (arr[st.top()] < arr[i])
            {
                ans.push_back(st.top());
                st.push(i);
                i -= 1;
            }
            else
            {
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxi = *max_element(heights.begin(), heights.end());

        vector<int> helper_left = nsl(heights, n);
        vector<int> helper_right = nsr(heights, n);

        for (int i = 0; i < n; i += 1)
        {
            int height = heights[i];
            int width = (i - helper_left[i] - 1) + 1 + (helper_right[i] - i - 1);
            maxi = max(maxi, height * width);
        }

        return maxi;
    }
};