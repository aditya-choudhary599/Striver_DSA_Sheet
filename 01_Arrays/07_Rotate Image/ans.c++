// Question Link : https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Here one imp observation if we take transpose of the given matrix and reverse each of its row then we get the rotate matrix
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // First we will take transpose of the matrix
        for (int i = 0; i < n; i += 1)
        {
            for (int j = i; j < n; j += 1)
            {
                //  This boundaries are taken to avoid the repatative swaps which will else result into the same matrix itself
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Now we have to reverse each row of the matrix
        for (int i = 0; i < n; i += 1)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return;
    }
};