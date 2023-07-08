// Question link : https://leetcode.com/problems/set-matrix-zeroes/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> row_vec(m, true);
        vector<bool> col_vec(n, true);

        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (matrix[i][j] == 0)
                {
                    row_vec[i] = false;
                    col_vec[j] = false;
                }
            }
        }

        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (row_vec[i] == false)
                {
                    matrix[i][j] = 0;
                }
                if (col_vec[j] == false)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};

// Time Complexity : 0(mn)
// Space Complexity : 0(m+n)