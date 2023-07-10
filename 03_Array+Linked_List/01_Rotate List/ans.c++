// Question Link : https://leetcode.com/problems/rotate-list/description/

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
    int length(ListNode *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        return 1 + length(head->next);
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return head;
        }
        int n = length(head);
        k = k % n;
        if (k == 0)
        {
            return head;
        }
        
        ListNode *temp = head;
        for (int i = 1; i < (n - k + 1) - 1; i += 1)
        {
            temp = temp->next;
        }
        ListNode *second_part_head = temp->next;
        temp->next = NULL;

        ListNode *helper = second_part_head;
        while (helper->next != NULL)
        {
            helper = helper->next;
        }
        helper->next = head;

        return second_part_head;
    }
};