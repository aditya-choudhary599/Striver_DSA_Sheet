// Question Link : https://leetcode.com/problems/count-and-say/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string small_ans = countAndSay(n - 1);
        int i = 0;
        int m = small_ans.length();
        string ans = "";

        while (i < m)
        {
            int cnt = 0;
            int j = i;
            while (j < m && small_ans[j] == small_ans[i])
            {
                j += 1;
                cnt += 1;
            }

            ans = ans + to_string(cnt) + small_ans[i];

            i = j;
        }

        return ans;
    }
};