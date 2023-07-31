// Question Link : https://www.codingninjas.com/studio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// This topo-sort algorithm is implemented using bfs and this algo was ta

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    vector<int> in_degree(n,0);
    unordered_map<int,vector<int>> adj_list;

    for(int i=0;i<e;i+=1)
    {
        adj_list[edges[i][0]].push_back(edges[i][1]);
        in_degree[edges[i][1]]+=1;
    }

    queue<int> q;
    for(int i=0;i<n;i+=1)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while(q.empty()!=true)
    {
        int top=q.front();
        ans.push_back(top);
        q.pop();

        int m=adj_list[top].size();
        for(int i=0;i<m;i+=1)
        {
            in_degree[adj_list[top][i]]-=1;
            if(in_degree[adj_list[top][i]]==0)
            {
                q.push(adj_list[top][i]);
            }
        }
    }

    return ans;
}