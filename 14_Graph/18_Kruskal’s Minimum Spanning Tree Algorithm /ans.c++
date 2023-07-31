#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codingninjas.com/studio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// This solution is inspired by the striver's soln video

class disjoint_set
{
private:
    vector<int> rank, parent;

public:
    disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i += 1)
        {
            parent[i] = i;
        }
    }

    int find_ultimate_parent(int child)
    {
        if (parent[child] == child)
        {
            return child;
        }

        // Path-compression step included
        return parent[child] = find_ultimate_parent(parent[child]);
    }

    void union_by_rank(int x, int y)
    {
        int ultimate_parent_of_x = find_ultimate_parent(x);
        int ultimate_parent_of_y = find_ultimate_parent(y);

        if (ultimate_parent_of_x == ultimate_parent_of_y)
        {
            return;
        }

        if (rank[ultimate_parent_of_x] < rank[ultimate_parent_of_y])
        {
            parent[ultimate_parent_of_x] = ultimate_parent_of_y;
        }
        else if (rank[ultimate_parent_of_x] > rank[ultimate_parent_of_y])
        {
            parent[ultimate_parent_of_y] = ultimate_parent_of_x;
        }
        else
        {
            parent[ultimate_parent_of_x] = ultimate_parent_of_y;
            rank[ultimate_parent_of_y] += 1;
        }
    }

    bool are_connected(int x, int y)
    {
        return find_ultimate_parent(x) == find_ultimate_parent(y);
    }
};

typedef pair<int, pair<int, int>> pq_pair;

int kruskalMST(int n, vector<vector<int>> &edges)
{
    // This question has 1-based indexing

    priority_queue<pq_pair, vector<pq_pair>, greater<pq_pair>> pq;
    for (auto edge : edges)
    {
        pq.push({edge[2], {edge[0], edge[1]}});
    }

    disjoint_set ds(n);
    int ans = 0;
    while (!pq.empty())
    {
        pq_pair top = pq.top();
        pq.pop();

        if (!ds.are_connected(top.second.first, top.second.second))
        {
            ds.union_by_rank(top.second.first, top.second.second);
            ans += top.first;
        }
    }
    return ans;
}