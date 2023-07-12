// Question Link : https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_799400?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i += 1)
    {
        nums.push_back({at[i], dt[i]});
    }
    sort(nums.begin(), nums.end());

    map<pair<int, int>, bool> mp;
    mp[nums[0]] = true;
    for (int i = 1; i < n; i += 1)
    {
        bool found = false;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first.second < nums[i].first)
            {
                mp[nums[i]] = true;
                mp.erase(it);
                found = true;
                break;
            }
        }
        if (found == false)
        {
            mp[nums[i]] = true;
        }
    }

    return mp.size();
}