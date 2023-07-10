// Question Link : https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *helper = head;
        while (helper != NULL)
        {
            if (mp.find(helper) == mp.end())
            {
                mp[helper] = new Node(helper->val);
            }
            if (helper->next != NULL)
            {
                mp[helper->next] = new Node(helper->next->val);
                mp[helper]->next = mp[helper->next];
            }
            else
            {
                mp[helper]->next = NULL;
            }

            helper = helper->next;
        }

        helper = head;
        while (helper != NULL)
        {
            if (helper->random != NULL)
            {
                mp[helper]->random = mp[helper->random];
            }
            helper = helper->next;
        }
        return mp[head];
    }
};