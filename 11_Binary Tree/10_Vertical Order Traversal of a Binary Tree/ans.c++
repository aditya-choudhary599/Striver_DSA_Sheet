// Question Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<pair<TreeNode *, int>> q;
        map<int, vector<int>> mp;
        q.push({root, 0});

        while (q.empty() != true)
        {
            int size = q.size();

            for (int i = 0; i < size; i += 1)
            {
                pair<TreeNode *, int> p = q.front();
                q.pop();
                mp[p.second].push_back(p.first->val);

                if (p.first->left != NULL)
                {
                    q.push({p.first->left, p.second - 1});
                }

                if (p.first->right != NULL)
                {
                    q.push({p.first->right, p.second + 1});
                }
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push(it->first);
        }

        vector<vector<int>> ans;
        while (pq.empty() != true)
        {
            ans.push_back(mp[pq.top()]);
            pq.pop();
        }

        return ans;
    }
};