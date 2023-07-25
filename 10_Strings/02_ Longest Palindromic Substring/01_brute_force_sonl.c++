// Question Link : https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_palindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        int counter = 0;
        string ans = "";
        for (int i = 0; i < n; i += 1)
        {
            string temp = "";
            for (int j = i; j < n; j += 1)
            {
                temp += s[j];
                if (is_palindrome(temp) == true)
                {
                    if (counter < temp.length())
                    {
                        counter = temp.length();
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};