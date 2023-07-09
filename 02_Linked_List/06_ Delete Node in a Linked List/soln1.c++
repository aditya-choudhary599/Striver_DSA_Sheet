// Question Link : https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node;
        ListNode *prev = NULL;
        while (temp->next != NULL)
        {
            temp->val = temp->next->val;
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        return;
    }
};