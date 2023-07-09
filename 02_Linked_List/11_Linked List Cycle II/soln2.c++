// Question Link : https://leetcode.com/problems/linked-list-cycle-ii/description/

// This code is inspired by the best solution algorithm that striver explained in his solution video of this problem

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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *temp = head;
                while (slow != temp)
                {
                    slow = slow->next;
                    temp = temp->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};