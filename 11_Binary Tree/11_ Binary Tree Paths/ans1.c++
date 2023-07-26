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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {to_string(root->val)};
        }

        vector<string> left_small_ans = binaryTreePaths(root->left);
        vector<string> right_small_ans = binaryTreePaths(root->right);

        for (int i = 0; i < left_small_ans.size(); i += 1)
        {
            left_small_ans[i] = to_string(root->val) + "->" + left_small_ans[i];
        }
        for (int i = 0; i < right_small_ans.size(); i += 1)
        {
            right_small_ans[i] = to_string(root->val) + "->" + right_small_ans[i];
        }
        
        left_small_ans.insert(left_small_ans.end(), right_small_ans.begin(), right_small_ans.end());
        return left_small_ans;
    }
};