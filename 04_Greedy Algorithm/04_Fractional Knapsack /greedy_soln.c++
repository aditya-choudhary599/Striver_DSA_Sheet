// Question Link : https://www.codingninjas.com/studio/problems/fractional-knapsack_975286?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // here items[i].first is the weight of the item
    // here items[i].second is the value of the item

    priority_queue<pair<double, pair<int, int>>> pq;
    for (int i = 0; i < n; i += 1)
    {
        pq.push({items[i].second * 1.0 / items[i].first, items[i]});
    }

    double ans = 0;
    while (pq.empty() != true && w > 0)
    {
        pair<double, pair<int, int>> p = pq.top();
        pq.pop();

        if (w >= p.second.first)
        {
            w -= p.second.first;
            ans += p.second.second;
        }
        else
        {
            ans = ans + ((w * 1.0 / p.second.first) * (p.second.second));
            w = 0;
        }
    }

    return ans;
}