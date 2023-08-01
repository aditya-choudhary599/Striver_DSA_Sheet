// Question Link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char ch;
    node *left, *right;
    bool end;

    node(char ch, node *left = NULL, node *right = NULL)
    {
        this->ch = ch;
        this->left = left;
        this->right = right;
        this->end = false;
        return;
    }
};

class Solution
{
public:
    void insert(node *root, string curr)
    {
        if (curr.length() == 0)
        {
            root->end = true;
            return;
        }

        if (curr[0] == '0')
        {
            if (root->left == NULL)
            {
                root->left = new node('0');
            }
            insert(root->left, curr.substr(1));
        }

        else
        {
            if (root->right == NULL)
            {
                root->right = new node('1');
            }
            insert(root->right, curr.substr(1));
        }

        return;
    }

    void helper(node *root, string curr, string &op)
    {
        if (curr.length() == 0)
        {
            return;
        }

        char temp = curr[0];
        if (temp == '0')
        {
            // So desirable is to get 1
            if (root->right != NULL)
            {
                op += '1';
                helper(root->right, curr.substr(1), op);
            }
            else if (root->left != NULL)
            {
                op += '0';
                helper(root->left, curr.substr(1), op);
            }
            else
            {
                return;
            }
        }
        else
        {
            // So desirable is to get 0
            if (root->left != NULL)
            {
                op += '0';
                helper(root->left, curr.substr(1), op);
            }
            else if (root->right != NULL)
            {
                op += '1';
                helper(root->right, curr.substr(1), op);
            }
            else
            {
                return;
            }
        }
    }

    int getMax(int x, node *root)
    {
        string curr = bitset<sizeof(int) * 8>(x).to_string();
        string op = "";
        helper(root, curr, op);
        int bro = stoi(op, nullptr, 2);
        return x ^ bro;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        node *root = new node('#');
        for (int i = 0; i < n; i += 1)
        {
            string curr = bitset<sizeof(int) * 8>(nums[i]).to_string();
            insert(root, curr);
        }

        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            ans = max(ans, getMax(nums[i], root));
        }

        return ans;
    }
};