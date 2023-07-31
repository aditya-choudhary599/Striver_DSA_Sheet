// Question Link : https://www.codingninjas.com/studio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// This algorithm is explained by striver in his solution video

#include <bits/stdc++.h>
using namespace std;

void step_1(int pos, stack<int> &st, vector<bool> &vis, vector<vector<int>> &org_graph)
{
    vis[pos] = true;

    for (auto con : org_graph[pos])
    {
        if (!vis[con])
        {
            step_1(con, st, vis, org_graph);
        }
    }

    st.push(pos);

    return;
}

void step_3(int pos, vector<bool> &vis, vector<int> &temp, vector<vector<int>> &rev_graph)
{
    vis[pos] = true;
    temp.push_back(pos);

    for (auto con : rev_graph[pos])
    {
        if (!vis[con])
        {
            step_3(con, vis, temp, rev_graph);
        }
    }

    return;
}

// Graph implementation using adj list
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> org_graph(n);
    vector<vector<int>> rev_graph(n);
    for (auto edge : edges)
    {
        org_graph[edge[0]].push_back(edge[1]);
        rev_graph[edge[1]].push_back(edge[0]);
    }

    /* Step 1 of algo : To sort the edges as per their finishing time with the one
    that finishes last on the top of the container we store them in */
    stack<int> st;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i += 1)
    {
        if (!vis[i])
        {
            step_1(i, st, vis, org_graph);
        }
    }

    /* Step 2 of algo : To reverse the graph which we have already done intially */

    /* Step 3 of algo : To finally print the SCC's */
    for (int i = 0; i < n; i += 1)
    {
        vis[i] = false;
    }
    vector<vector<int>> ans;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            vector<int> temp;
            step_3(top, vis, temp, rev_graph);
            ans.push_back(temp);
        }
    }

    return ans;
}