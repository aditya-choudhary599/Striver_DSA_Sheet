// Question Link : https://leetcode.com/problems/search-a-2d-matrix/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool f(int i,int j,int m,int n,int target,vector<vector<int>>& matrix)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return false;
        }
        if(matrix[i][j]==target)
        {
            return true;
        }
        if(matrix[i][j]<target)
        {
            return f(i+1,j,m,n,target,matrix);
        }
        else
        {
            return f(i,j-1,m,n,target,matrix);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        return f(0,n-1,m,n,target,matrix);
    }
};