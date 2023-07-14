// Question Link : https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_safe(int x, int y, int n, vector<vector<bool>> &marked)
    {
        // Checking in north-south direction
        for (int i = 0; i < n; i += 1)
        {
            if (marked[i][y] == true)
            {
                return false;
            }
        }

        // Checking in east-west direction
        for (int j = 0; j < n; j += 1)
        {
            if (marked[x][j] == true)
            {
                return false;
            }
        }

        // Checking in northwest-direction
        int p = x, q = y;
        while (p >= 0 && q >= 0)
        {
            if (marked[p][q] == true)
            {
                return false;
            }
            p -= 1;
            q -= 1;
        }

        // Checking in southwest-direction
        p = x, q = y;
        while (p < n && q >= 0)
        {
            if (marked[p][q] == true)
            {
                return false;
            }
            p += 1;
            q -= 1;
        }

        // Checking in northeast-direction
        p = x, q = y;
        while (p >= 0 && q < n)
        {
            if (marked[p][q] == true)
            {
                return false;
            }
            p -= 1;
            q += 1;
        }

        // Checking in southeast-direction
        p = x, q = y;
        while (p < n && q < n)
        {
            if (marked[p][q] == true)
            {
                return false;
            }
            p += 1;
            q += 1;
        }

        return true;
    }

    void f(int index, int n, vector<vector<bool>> &marked, vector<vector<string>> &ans, vector<string> &temp)
    {
        if (index == n)
        {
            ans.push_back(temp);
            return;
        }

        string head = "";
        string tail = "";
        for (int x = 0; x < n; x++)
        {
            tail += '.';
        }

        for (int j = 0; j < n; j += 1)
        {
            tail.pop_back();
            if (is_safe(index, j, n, marked) == true)
            {
                // Recursive call
                marked[index][j] = true;
                string curr = head + 'Q' + tail;
                temp.push_back(curr);
                f(index + 1, n, marked, ans, temp);

                // Bactracking
                temp.pop_back();
                marked[index][j] = false;
            }
            head.push_back('.');
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<bool>> marked(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        vector<string> temp;
        f(0, n, marked, ans, temp);
        return ans;
    }
};