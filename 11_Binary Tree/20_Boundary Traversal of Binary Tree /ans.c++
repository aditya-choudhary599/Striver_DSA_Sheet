// Question Link : https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

typedef TreeNode<int> tree_node;

void fill_v1(tree_node *root, vector<tree_node *> &v1)
{
    if (root == NULL)
    {
        return;
    }

    v1.push_back(root);
    if (root->left != NULL)
    {
        fill_v1(root->left, v1);
        return;
    }
    else if (root->right != NULL)
    {
        fill_v1(root->right, v1);
        return;
    }

    return;
}

void fill_v2(tree_node *root, vector<tree_node *> &v2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        v2.push_back(root);
        return;
    }

    fill_v2(root->left, v2);
    fill_v2(root->right, v2);
    return;
}

void fill_v3(tree_node *root, vector<tree_node *> &v3)
{
    if (root == NULL)
    {
        return;
    }
    v3.push_back(root);
    if (root->right != NULL)
    {
        fill_v3(root->right, v3);
        return;
    }
    else if (root->left != NULL)
    {
        fill_v3(root->left, v3);
        return;
    }

    return;
}

vector<int> traverseBoundary(tree_node *root)
{
    vector<tree_node *> v1;
    if (root->left != NULL)
    {
        fill_v1(root, v1);
    }
    else
    {
        v1.push_back(root);
    }

    vector<tree_node *> v2;
    fill_v2(root, v2);

    vector<tree_node *> v3;
    if (root->right != NULL)
    {
        fill_v3(root, v3);
        reverse(v3.begin(), v3.end());
    }

    unordered_map<tree_node *, bool> mp;
    vector<int> op;

    int n = v1.size();
    for (int i = 0; i < n; i += 1)
    {
        op.push_back(v1[i]->data);
        mp[v1[i]] = true;
    }

    n = v2.size();
    for (int i = 0; i < n; i += 1)
    {
        if (mp.find(v2[i]) == mp.end())
        {
            op.push_back(v2[i]->data);
            mp[v2[i]] = true;
        }
    }

    n = v3.size();
    for (int i = 0; i < n; i += 1)
    {
        if (mp.find(v3[i]) == mp.end())
        {
            op.push_back(v3[i]->data);
            mp[v3[i]] = true;
        }
    }

    return op;
}