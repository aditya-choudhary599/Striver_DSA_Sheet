// Question Link : https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// This algo was expalined by striver in his solution video of this problem

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

vector<int> getInOrderTraversal(TreeNode *curr)
{
    vector<int> inOrder;
    stack<TreeNode *> s;

    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        else
        {
            if (s.empty())
                break;
            curr = s.top();
            inOrder.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }
    }
    return inOrder;
}