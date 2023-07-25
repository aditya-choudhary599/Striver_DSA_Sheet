// Question Link : https://leetcode.com/problems/roman-to-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> mp = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}};
        int n = s.length();
        int ans = 0;
        int i = 0;
        while (i < n)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < n)
                {
                    if (s[i + 1] == 'V')
                    {
                        ans += mp["IV"];
                        i += 2;
                    }
                    else if (s[i + 1] == 'X')
                    {
                        ans += mp["IX"];
                        i += 2;
                    }
                    else
                    {
                        ans += mp["I"];
                        i += 1;
                    }
                }
                else
                {
                    ans += mp["I"];
                    i += 1;
                }
            }
            else if (s[i] == 'X')
            {
                if (i + 1 < n)
                {
                    if (s[i + 1] == 'L')
                    {
                        ans += mp["XL"];
                        i += 2;
                    }
                    else if (s[i + 1] == 'C')
                    {
                        ans += mp["XC"];
                        i += 2;
                    }
                    else
                    {
                        ans += mp["X"];
                        i += 1;
                    }
                }
                else
                {
                    ans += mp["X"];
                    i += 1;
                }
            }
            else if (s[i] == 'C')
            {
                if (i + 1 < n)
                {
                    if (s[i + 1] == 'D')
                    {
                        ans += mp["CD"];
                        i += 2;
                    }
                    else if (s[i + 1] == 'M')
                    {
                        ans += mp["CM"];
                        i += 2;
                    }
                    else
                    {
                        ans += mp["C"];
                        i += 1;
                    }
                }
                else
                {
                    ans += mp["C"];
                    i += 1;
                }
            }
            else
            {
                string temp = "";
                temp += s[i];
                ans += mp[temp];
                i += 1;
            }
        }

        return ans;
    }
};