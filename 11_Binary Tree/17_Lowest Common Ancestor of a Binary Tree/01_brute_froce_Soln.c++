// Question Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void trace_path(TreeNode *root, TreeNode *target, vector<int> &path)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val == target->val)
        {
            path.push_back(target->val);
            return;
        }

        vector<int> small_left_path, small_right_path;
        trace_path(root->left, target, small_left_path);
        trace_path(root->right, target, small_right_path);

        if (small_left_path.size() != 0)
        {
            path.insert(path.end(), small_left_path.begin(), small_left_path.end());
            path.push_back(root->val);
        }
        else if (small_right_path.size() != 0)
        {
            path.insert(path.end(), small_right_path.begin(), small_right_path.end());
            path.push_back(root->val);
        }
        else
        {
            return;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<int> path_1, path_2;
        trace_path(root, p, path_1);
        trace_path(root, q, path_2);

        reverse(path_1.begin(), path_1.end());
        reverse(path_2.begin(), path_2.end());

        unordered_map<int, bool> mp;
        for (int i = 0; i < path_1.size(); i++)
        {
            mp[path_1[i]] = true;
        }
        for (int i = path_2.size() - 1; i >= 0; i--)
        {
            if (mp.find(path_2[i]) != mp.end())
            {
                TreeNode *ans = new TreeNode(path_2[i]);
                return ans;
            }
        }
        return NULL;
    }
};