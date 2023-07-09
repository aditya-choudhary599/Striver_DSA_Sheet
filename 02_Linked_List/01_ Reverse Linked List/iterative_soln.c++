// Question Link : https://leetcode.com/problems/reverse-linked-list/

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
        ListNode *prev = head, *curr = head->next;
        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            if (prev == head)
            {
                prev->next = NULL;
            }
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};