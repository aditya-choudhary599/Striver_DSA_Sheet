// Question Link : https://www.codingninjas.com/studio/problems/postorder-traversal_3839614?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void fill(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    fill(root->left, ans);
    fill(root->right, ans);
    ans.push_back(root->data);
    return;
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    fill(root, ans);
    return ans;
}