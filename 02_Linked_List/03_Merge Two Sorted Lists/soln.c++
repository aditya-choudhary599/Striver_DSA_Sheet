// Question Link : https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(INT_MAX);
        ListNode *temp = dummy;

        ListNode *i = list1, *j = list2;

        while (i != NULL && j != NULL)
        {
            if (i->val <= j->val)
            {
                ListNode *new_node = new ListNode(i->val);
                temp->next = new_node;
                temp = new_node;
                i = i->next;
            }
            else
            {
                ListNode *new_node = new ListNode(j->val);
                temp->next = new_node;
                temp = new_node;
                j = j->next;
            }
        }

        while (i != NULL)
        {
            ListNode *new_node = new ListNode(i->val);
            temp->next = new_node;
            temp = new_node;
            i = i->next;
        }
        while (j != NULL)
        {
            ListNode *new_node = new ListNode(j->val);
            temp->next = new_node;
            temp = new_node;
            j = j->next;
        }

        return dummy->next;
    }
};