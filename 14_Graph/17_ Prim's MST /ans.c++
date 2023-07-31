// Question Link : https://www.codingninjas.com/studio/problems/1095633?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> input_pair;
typedef pair<int, pair<int, int>> pq_pair;

vector<input_pair> calculatePrimsMST(int n, int m, vector<input_pair> &edges)
{
    // Here 1-based indexing and graph is implemented using the adj list
    vector<vector<pair<int, int>>> graph(n + 1);

    for (auto edge : edges)
    {
        graph[edge.first.first].push_back({edge.first.second, edge.second});
        graph[edge.first.second].push_back({edge.first.first, edge.second});
    }

    vector<bool> vis(n + 1, false);
    priority_queue<pq_pair, vector<pq_pair>, greater<pq_pair>> min_heap;
    min_heap.push({0, {1, -1}});

    vector<input_pair> ans;
    while (!min_heap.empty())
    {
        pq_pair top = min_heap.top();
        min_heap.pop();

        if (!vis[top.second.first])
        {
            vis[top.second.first] = true;
            if (top.second.second != -1)
            {
                ans.push_back({top.second, top.first});
            }

            for (auto con : graph[top.second.first])
            {
                min_heap.push({con.second, {con.first, top.second.first}});
            }
        }
    }

    return ans;
}
