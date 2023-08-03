// Question Link : https://www.codingninjas.com/studio/problems/873266?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string &s, unordered_map<string, bool> &mp)
{
    if (mp.find(s) != mp.end())
    {
        return mp[s];
    }
    string rev = s;
    reverse(rev.begin(), rev.end());
    return mp[s] = rev == s;
}

int helper(string str, unordered_map<string, bool> &mp)
{
    int n = str.length();

    if (n == 0)
    {
        return 0;
    }

    string curr = "";
    int ans = 1000;

    for (int i = 0; i < n; ++i)
    {
        curr += str[i];
        if (isPalindrome(curr, mp))
        {
            ans = min(ans, 1 + helper(str.substr(i + 1), mp));
        }
    }

    return ans;
}

int palindromePartitioning(string str)
{
    unordered_map<string, bool> mp;
    return helper(str, mp) - 1;
}
