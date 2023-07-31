// Question Link : https://www.codingninjas.com/studio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Here graph is implemnted using the adj list
vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source)
{
    vector<vector<pair<int, int>>> graph(n);
    for (auto edge : vec)
    {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> dis(n, INT_MAX);
    dis[source] = 0;

    queue<pair<int, int>> q;
    q.push({source, 0});

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();

        for (auto con : graph[top.first])
        {
            if (dis[con.first] == INT_MAX || dis[con.first] > top.second + con.second)
            {
                dis[con.first] = top.second + con.second;
                q.push({con.first, dis[con.first]});
            }
        }
    }

    return dis;
}
