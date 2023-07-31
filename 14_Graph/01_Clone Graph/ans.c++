// Question Link : https://leetcode.com/problems/clone-graph/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> mp;

        mp[root] = new Node(root->val);

        unordered_map<Node *, bool> vis;
        queue<Node *> q;
        q.push(root);

        while (q.empty() != true)
        {
            Node *front = q.front();
            if (vis.find(front) == vis.end())
            {
                vis[front] = true;

                int m = front->neighbors.size();

                for (int i = 0; i < m; i += 1)
                {
                    if (mp.find(front->neighbors[i]) == mp.end())
                    {
                        mp[front->neighbors[i]] = new Node(front->neighbors[i]->val);
                    }

                    mp[front]->neighbors.push_back(mp[front->neighbors[i]]);

                    q.push(front->neighbors[i]);
                }
            }

            q.pop();
        }

        return mp[root];
    }
};