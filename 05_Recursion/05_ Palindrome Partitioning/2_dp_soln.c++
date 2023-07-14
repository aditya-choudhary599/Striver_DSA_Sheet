// Question Link : https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }

    vector<vector<string>> g(string s, map<string, vector<vector<string>>> &dp)
    {
        if (s.length() == 0)
        {
            return {{}};
        }
        if (s.length() == 1)
        {
            string ans = "";
            ans += s[0];
            return {{ans}};
        }
        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }
        int n = s.length();
        vector<vector<string>> ans;
        string helper = "";
        for (int i = 0; i < n; i += 1)
        {
            helper += s[i];
            if (f(helper) == true)
            {
                vector<vector<string>> rcall = g(s.substr(i + 1), dp);
                int size = rcall.size();
                for (int j = 0; j < size; j += 1)
                {
                    vector<string> curr = rcall[j];
                    curr.insert(curr.begin(), helper);
                    ans.push_back(curr);
                }
            }
        }
        return dp[s] = ans;
    }

    vector<vector<string>> partition(string s)
    {
        map<string, vector<vector<string>>> dp;
        return g(s, dp);
    }
};