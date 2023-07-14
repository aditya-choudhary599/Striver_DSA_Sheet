// Question Link : https://leetcode.com/problems/permutation-sequence/description/

// It is better than ans1 because here we are avoiding the unecessary functional calls using the logic of permuation and combination

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int factorial(int n)
    {
        // single line to find factorial
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }

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

        ch = '1';
        int fact = factorial(n - 1);
        while (k != 0)
        {
            if (fact < k)
            {
                k -= fact;
                ch++;
            }
            else
            {
                mp[ch] = false;
                vector<string> ans;
                string temp = "";
                f(mp, n - 1, temp, ans);
                sort(ans.begin(), ans.end());
                return ch + ans[k - 1];
            }
        }
        return "";
    }
};