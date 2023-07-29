// Question Link : https://www.codingninjas.com/studio/problems/920336?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    int n = arr.size();

    for (int i = 0; i < k; i += 1)
    {
        mp[arr[i]] += 1;
    }

    vector<int> ans;
    for (int i = k; i < n; i += 1)
    {
        ans.push_back(mp.size());

        mp[arr[i - k]] -= 1;
        if (mp[arr[i - k]] == 0)
        {
            mp.erase(arr[i - k]);
        }
        mp[arr[i]] += 1;
    }

    // For last iteration
    ans.push_back(mp.size());

    return ans;
}
