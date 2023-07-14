// Question Link : https://leetcode.com/problems/word-break-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> f(string s, unordered_map<string, bool> &mp)
    {
        if (s.length() == 0)
        {
            return {""};
        }
        int n = s.length();
        string temp = "";
        vector<string> ans;
        for (int i = 0; i < n; i += 1)
        {
            temp += s[i];
            if (mp.find(temp) != mp.end())
            {
                vector<string> small_ans = f(s.substr(i + 1), mp);
                int m = small_ans.size();
                for (int j = 0; j < m; j += 1)
                {
                    string helper = temp + " " + small_ans[j];
                    ans.push_back(helper);
                }
            }
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> mp;
        int n = wordDict.size();
        for (int i = 0; i < n; i += 1)
        {
            mp[wordDict[i]] = true;
        }
        vector<string> ans = f(s, mp);
        for (int i = 0; i < ans.size(); i += 1)
        {
            ans[i] = ans[i].substr(0, ans[i].size() - 1); // for removing last extra trailing space
        }
        return ans;
    }
};