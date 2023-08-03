// Question Link : https://www.codingninjas.com/studio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// This code is inspired by the solution of striver from his dp series

#include <bits/stdc++.h> 
using namespace std;

int f(int start,int end,vector<pair<int,int>> mat,map <pair<int,int>,int> &dp)
{
    if(start==end)
    {
        return 0;
    }
    
    if(dp.find({start,end})!=dp.end())
    {
        return dp[{start,end}];
    }
    
    int ans=INT_MAX;
    for(int x=start;x<end;x+=1)
    {
        int left=f(start,x,mat,dp);
        int right=f(x+1,end,mat,dp);

        ans=min(ans,left+right+mat[start].first*mat[x+1].first*mat[end].second);
    }

    return dp[{start,end}]=ans;
}

int matrixMultiplication(vector<int> &arr, int n)
{
    map <pair<int,int>,int> dp;
    vector<pair<int,int>> mat;
    for(int i=0;i<n-1;i+=1)
    {
        mat.push_back({arr[i],arr[i+1]});
    }
    return f(0,n-2,mat,dp);
}