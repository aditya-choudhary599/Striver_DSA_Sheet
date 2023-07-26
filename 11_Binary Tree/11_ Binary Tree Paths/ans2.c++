// Question Link : https://leetcode.com/problems/binary-tree-paths/

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
    void fill(TreeNode *root, vector<string> &ans, string temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            temp = temp + "->" + to_string(root->val);
            ans.push_back(temp);
            return;
        }

        string helper = temp + "->" + to_string(root->val);
        if (root->left != NULL)
        {
            fill(root->left, ans, helper);
        }
        if (root->right != NULL)
        {
            fill(root->right, ans, helper);
        }

        return;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string temp = "";
        fill(root, ans, temp);
        int m = ans.size();

        // Removing the starting impurities
        for (int i = 0; i < m; i += 1)
        {
            ans[i] = ans[i].substr(2);
        }
        return ans;
    }
};