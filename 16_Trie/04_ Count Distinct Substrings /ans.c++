// Question Link :https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int countDistinctSubstrings(string &s)
{
    int n = s.length();
    int ans = 0;
    unordered_map<string, bool> mp;
    for (int i = 0; i < n; i += 1)
    {
        string temp = "";
        for (int j = i; j < n; j += 1)
        {
            temp += s[j];
            if (mp.find(temp) == mp.end())
            {
                ans += 1;
                mp[temp] = true;
            }
        }
    }

    return ans + 1;
    // 1 for ""
}