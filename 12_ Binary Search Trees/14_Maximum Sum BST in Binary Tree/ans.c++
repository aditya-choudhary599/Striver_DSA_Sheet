// Question Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

// This algo was implemented as explained by striver in his soln video

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

class trio
{
public:
    int low_bound;
    int high_bound;
    bool is_BST;
    int sum;
};

class Solution
{
public:
    trio f(TreeNode *root, int &maxi)
    {
        trio curr;
        if (root->left != NULL && root->right != NULL)
        {
            trio left = f(root->left, maxi);
            trio right = f(root->right, maxi);

            if (left.is_BST == true && right.is_BST == true && left.high_bound < root->val && root->val < right.low_bound)
            {
                maxi = max(maxi, left.sum + right.sum + root->val);
                curr.low_bound = left.low_bound;
                curr.high_bound = right.high_bound;
                curr.is_BST = true;
                curr.sum = left.sum + right.sum + root->val;
                return curr;
            }
            else
            {
                curr.low_bound = left.low_bound;
                curr.high_bound = right.high_bound;
                curr.is_BST = false;
                curr.sum = 0;
                return curr;
            }
        }

        else if (root->left == NULL && root->right != NULL)
        {
            trio right = f(root->right, maxi);
            if (right.is_BST == true && root->val < right.low_bound)
            {
                maxi = max(maxi, right.sum + root->val);
                curr.low_bound = root->val;
                curr.high_bound = right.high_bound;
                curr.is_BST = true;
                curr.sum = right.sum + root->val;
                return curr;
            }
            else
            {
                curr.low_bound = root->val;
                curr.high_bound = right.high_bound;
                curr.is_BST = false;
                curr.sum = 0;
                return curr;
            }
        }

        else if (root->left != NULL && root->right == NULL)
        {
            trio left = f(root->left, maxi);
            if (left.is_BST == true && root->val > left.high_bound)
            {
                maxi = max(maxi, left.sum + root->val);
                curr.low_bound = left.low_bound;
                curr.high_bound = root->val;
                curr.is_BST = true;
                curr.sum = left.sum + root->val;
                return curr;
            }
            else
            {
                curr.low_bound = left.low_bound;
                curr.high_bound = root->val;
                curr.is_BST = false;
                curr.sum = 0;
                return curr;
            }
        }

        else
        {
            maxi = max(maxi, root->val);
            curr.low_bound = root->val;
            curr.high_bound = root->val;
            curr.is_BST = true;
            curr.sum = root->val;
            return curr;
        }
    }

    int maxSumBST(TreeNode *root)
    {
        int maxi = 0;
        f(root, maxi);
        return maxi;
    }
};