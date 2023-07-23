// Question Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // each individual building is al rectangle
        int maxi = *max_element(heights.begin(), heights.end());
        int n = heights.size();
        for (int i = 0; i < n; i += 1)
        {
            int width = 1;
            int j = i - 1;
            int maxi1 = 0, maxi2 = 0;
            while (j >= 0 && heights[j] >= heights[i])
            {
                width += 1;
                maxi1 = max(maxi1, width * heights[i]);
                j -= 1;
            }

            if (maxi1 == 0)
            {
                // No left protion is their so we can count curr one in right portion
                width = 1;
            }
            else
            {
                // Left protion is their so we cannot count curr one in right portion
                width = 0;
            }

            j = i + 1;
            while (j < n && heights[j] >= heights[i])
            {
                width += 1;
                maxi2 = max(maxi2, width * heights[i]);
                j += 1;
            }

            maxi = max(maxi, maxi1 + maxi2);
        }

        return maxi;
    }
};