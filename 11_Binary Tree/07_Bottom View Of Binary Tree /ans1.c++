// Question Link : https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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

void fill(BinaryTreeNode<int> *root, int mark, map<int, int> &mp)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    while (q.empty() != true)
    {
        pair<BinaryTreeNode<int> *, int> front = q.front();
        mp[front.second] = front.first->data;
        q.pop();

        if (front.first->left != NULL)
        {
            q.push({front.first->left, front.second - 1});
        }

        if (front.first->right != NULL)
        {
            q.push({front.first->right, front.second + 1});
        }
    }

    return;
}

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    map<int, int> mp;
    fill(root, 0, mp);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push(it->first);
    }

    vector<int> ans;
    while (pq.empty() != true)
    {
        ans.push_back(mp[pq.top()]);
        pq.pop();
    }

    return ans;
}
