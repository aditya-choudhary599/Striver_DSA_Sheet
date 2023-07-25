// Question Link : https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string f(int index, int n, vector<string> &arr)
    {
        if (index == n - 1)
        {
            return arr[index];
        }
        string rcall = f(index + 1, n, arr);

        int p = arr[index].length(), q = rcall.length();
        int i = 0, j = 0;

        string op = "";
        while (i < p && j < q)
        {
            if (arr[index][i] == rcall[j])
            {
                op += rcall[j];
                i += 1;
                j += 1;
            }
            else
            {
                return op;
            }
        }
        return op;
    }

    string longestCommonPrefix(vector<string> &arr)
    {
        return f(0, arr.size(), arr);
    }
};