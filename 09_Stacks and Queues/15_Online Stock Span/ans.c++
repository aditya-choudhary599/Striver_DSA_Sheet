// Question Link : https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    // Here logic of NGL is implemented

    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int ans = 1;
        while (st.empty() != true)
        {
            if (st.top().first > price)
            {
                st.push({price, ans});
                return ans;
            }
            else
            {
                ans += st.top().second;
                st.pop();
            }
        }
        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */