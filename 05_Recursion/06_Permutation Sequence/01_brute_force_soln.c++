// Question Link : https://leetcode.com/problems/permutation-sequence/

// This solution gives TLE

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(unordered_map<char, bool> &mp, int n, string &temp, vector<string> &ans)
    {
        if (n == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == true)
            {
                // Recursive call
                char curr = it->first;
                temp += curr;
                mp[curr] = false;
                f(mp, n - 1, temp, ans);

                // Backtracking
                mp[curr] = true;
                temp.pop_back();
            }
        }
        return;
    }

    string getPermutation(int n, int k)
    {
        char ch = '1';
        unordered_map<char, bool> mp;
        for (int i = 1; i <= n; i += 1)
        {
            mp[ch] = true;
            ch++;
        }

        vector<string> ans;
        string temp = "";
        f(mp, n, temp, ans);

        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};