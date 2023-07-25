// Question Link : https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string input)
    {
        stack<string> st;
        int n = input.length();
        string helper = "";
        for (int i = 0; i < n; i++)
        {
            if (input[i] == ' ')
            {
                if (helper == "")
                {
                    continue;
                }
                else
                {
                    st.push(helper);
                    helper = "";
                }
            }
            else
            {
                helper += input[i];
            }
        }
        if (helper != "")
        {
            st.push(helper);
        }

        input = "";
        while (st.empty() != true)
        {
            input += st.top();
            st.pop();
            if (st.size() >= 1)
            {
                input += " ";
            }
        }
        return input;
    }
};