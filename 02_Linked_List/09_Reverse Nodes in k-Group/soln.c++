// Question Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *small_ans = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return small_ans;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *temp = head;
        for (int i = 1; i < k && temp != NULL; i += 1)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return head;
        }
        ListNode *small_ans = reverseKGroup(temp->next, k);
        temp->next = NULL;
        ListNode *new_head = reverseList(head);
        head->next = small_ans;
        return new_head;
    }
};