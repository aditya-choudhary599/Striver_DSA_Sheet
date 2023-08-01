// Question Link : https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

bool check(string s, unordered_map<string, bool> &mp)
{
    string pre = "";
    int n = s.length();
    for (int i = 0; i < n; i += 1)
    {
        pre += s[i];
        if (mp.find(pre) == mp.end())
        {
            return false;
        }
    }
    return true;
}

string completeString(int n, vector<string> &arr)
{
    string ans = "";

    unordered_map<string, bool> mp;
    for (auto str : arr)
    {
        mp[str] = true;
    }

    for (auto str : arr)
    {
        if (check(str, mp))
        {
            if (ans.length() < str.length())
            {
                ans = max(ans, str);
            }
            else if (ans.length() == str.length())
            {
                ans = min(ans, str);
            }
        }
    }
    if (ans == "")
    {
        return "None";
    }
    return ans;
}