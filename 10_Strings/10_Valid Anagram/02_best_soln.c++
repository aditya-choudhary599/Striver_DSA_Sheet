// Question Link : https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n != m)
        {
            return false;
        }

        unordered_map<char, int> freq;
        for (int i = 0; i < n; i += 1)
        {
            freq[s[i]] += 1;
        }

        for (int i = 0; i < m; i += 1)
        {
            if (freq.find(t[i]) == freq.end())
            {
                return false;
            }
            else
            {
                if (freq[t[i]] == 0)
                {
                    return false;
                }
                else
                {
                    freq[t[i]] -= 1;
                }
            }
        }

        for (auto it : freq)
        {
            if (it.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};