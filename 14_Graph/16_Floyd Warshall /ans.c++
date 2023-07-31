// Question Link : https://www.codingninjas.com/studio/problems/2041979?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// This algo was explained by striver in his graph series

// Here we will implement the graph using the adj matrix
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    // 1 based indexing
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e9));
    for (auto edge : edges)
    {
        graph[edge[0]][edge[1]] = edge[2];
    }

    for (int i = 1; i <= n; i += 1)
    {
        graph[i][i] = 0;
    }

    for (int num = 1; num <= n; num++)
    {
        for (int i = 1; i <= n; i += 1)
        {
            for (int j = 1; j <= n; j += 1)
            {
                if (graph[i][num] != 1e9 && graph[num][j] != 1e9)
                {
                    graph[i][j] = min(graph[i][j], graph[i][num] + graph[num][j]);
                }
            }
        }
    }

    return graph[src][dest];
}