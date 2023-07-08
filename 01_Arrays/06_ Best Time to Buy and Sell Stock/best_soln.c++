// Question link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> temp(n);
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i -= 1)
        {
            maxi = max(maxi, prices[i]);
            temp[i] = maxi;
        }
        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            ans = max(ans, temp[i] - prices[i]);
        }
        return ans;
    }
};