// Question Link : https://www.codingninjas.com/studio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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
};

vector<int> getLeftView(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<vector<int>> levels;

    while (q.empty() != true)
    {
        int size = q.size();

        vector<int> curr_level;
        for (int i = 0; i < size; i += 1)
        {
            TreeNode<int> *front = q.front();
            q.pop();
            curr_level.push_back(front->data);

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }

        levels.push_back(curr_level);
    }

    vector<int> final_ans;
    int m = levels.size();
    for (int i = 0; i < m; i += 1)
    {
        if (levels[i].size() >= 1)
        {
            final_ans.push_back(levels[i][0]);
        }
    }

    return final_ans;
}