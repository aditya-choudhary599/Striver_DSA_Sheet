// Question Link : https://www.codingninjas.com/studio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// This is algorithm is implemented as per the way striver taught

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;

    // Running the outer loop for n-1 times
    for (int i = 0; i < n - 1; i += 1)
    {
        for (auto edge : edges)
        {
            if (dis[edge[0]] != 1e9 && dis[edge[0]] + edge[2] < dis[edge[1]])
            {
                dis[edge[1]] = dis[edge[0]] + edge[2];
            }
        }
    }

    return dis[dest];
}