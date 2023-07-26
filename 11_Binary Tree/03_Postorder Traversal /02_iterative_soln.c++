// Question Link : https://www.codingninjas.com/studio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

vector<int> getPostOrderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);

    while (st.empty() != true)
    {
        TreeNode *top = st.top();
        ans.push_back(top->data);
        st.pop();

        if (top->left != NULL)
        {
            st.push(top->left);
        }

        if (top->right != NULL)
        {
            st.push(top->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
