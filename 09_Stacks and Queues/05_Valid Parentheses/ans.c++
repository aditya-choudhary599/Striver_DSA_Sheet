// Question Link : https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    if (st.empty() == true || st.top() != '(')
                    {
                        return false;
                    }
                }
                else if (s[i] == '}')
                {
                    if (st.empty() == true || st.top() != '{')
                    {
                        return false;
                    }
                }
                else
                {
                    if (st.empty() == true || st.top() != '[')
                    {
                        return false;
                    }
                }
                st.pop();
            }

            i += 1;
        }

        return st.empty();
    }
};