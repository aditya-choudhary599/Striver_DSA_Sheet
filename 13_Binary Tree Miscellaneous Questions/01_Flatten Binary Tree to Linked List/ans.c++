// Question Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    TreeNode *f(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return root;
        }

        TreeNode *small_left = f(root->left);
        TreeNode *small_right = f(root->right);

        root->left = NULL;
        root->right = small_left;

        TreeNode *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }

        temp->right = small_right;
        return root;
    }

    void flatten(TreeNode *root)
    {
        root = f(root);
        return;
    }
};