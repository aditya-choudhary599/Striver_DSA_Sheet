// Question Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int f(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return -1 * 1e9;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        }

        int lcall = f(root->left, maxi);
        int rcall = f(root->right, maxi);

        // Options for maxi
        vector<int> temp_1 = {lcall, rcall, lcall + root->val, rcall + root->val, rcall + lcall + root->val, root->val, maxi};
        maxi = *max_element(temp_1.begin(), temp_1.end());

        // Options for returning
        vector<int> temp_2 = {lcall + root->val, rcall + root->val, root->val};
        return *max_element(temp_2.begin(), temp_2.end());
    }

    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        int maxi = INT_MIN;
        int temp = f(root, maxi);
        return maxi;
    }
};