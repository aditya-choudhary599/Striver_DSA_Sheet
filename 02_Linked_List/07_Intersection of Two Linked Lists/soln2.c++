// Question Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <bits/stdc++.h>
using namespace std;

// This solution is inspired by the first best solution given by striver in his solution video of this question

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

    ListNode *f(ListNode *big, ListNode *small, int cnt)
    {
        ListNode *dummy = big;
        while (cnt > 0)
        {
            dummy = dummy->next;
            cnt -= 1;
        }
        ListNode *temp_1 = dummy, *temp_2 = small;
        while (temp_1 != NULL && temp_2 != NULL && temp_1 != temp_2)
        {
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }
        if (temp_1 == NULL || temp_2 == NULL)
        {
            // This means no intersection exits in two linked lists
            return NULL;
        }
        return temp_1;
    }

    ListNode *getIntersectionNode(ListNode *head_1, ListNode *head_2)
    {
        int size_1 = length(head_1);
        int size_2 = length(head_2);

        if (size_1 <= size_2)
        {
            return f(head_2, head_1, size_2 - size_1);
        }
        return f(head_1, head_2, size_1 - size_2);
    }
};