// Question Link : https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, int m, int n)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        return f(i + 1, j, m, n) + f(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return f(0, 0, m, n);
    }
};