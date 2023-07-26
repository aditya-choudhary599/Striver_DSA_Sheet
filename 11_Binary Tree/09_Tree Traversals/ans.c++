// Question link : https://www.codingninjas.com/studio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// This code is implemented as per the algorithm explained by striver in his solution video

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return {{}, {}, {}};
    }
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    vector<int> ino, pre, post;

    while (st.empty() != true)
    {
        pair<BinaryTreeNode<int> *, int> p = st.top();
        if (p.second == 1)
        {
            pre.push_back(p.first->data);
            st.top().second += 1;
            if (p.first->left != NULL)
            {
                st.push({p.first->left, 1});
            }
        }
        else if (p.second == 2)
        {
            ino.push_back(p.first->data);
            st.top().second += 1;
            if (p.first->right != NULL)
            {
                st.push({p.first->right, 1});
            }
        }
        else
        {
            post.push_back(p.first->data);
            st.pop();
        }
    }

    return {ino, pre, post};
}