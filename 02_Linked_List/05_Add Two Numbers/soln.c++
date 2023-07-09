// Question Link : https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *head_1, ListNode *head_2)
    {
        ListNode *temp_1 = head_1, *temp_2 = head_2;

        ListNode *dummy = new ListNode(-1);
        ListNode *insert = dummy;
        int carry = 0;

        while (temp_1 != NULL && temp_2 != NULL)
        {
            int curr_sum = temp_1->val + temp_2->val + carry;

            ListNode *new_node = new ListNode(curr_sum % 10);
            insert->next = new_node;
            insert = new_node;

            carry = curr_sum / 10;

            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }

        while (temp_1 != NULL)
        {
            int curr_sum = temp_1->val + carry;

            ListNode *new_node = new ListNode(curr_sum % 10);
            insert->next = new_node;
            insert = new_node;

            carry = curr_sum / 10;

            temp_1 = temp_1->next;
        }

        while (temp_2 != NULL)
        {
            int curr_sum = temp_2->val + carry;

            ListNode *new_node = new ListNode(curr_sum % 10);
            insert->next = new_node;
            insert = new_node;

            carry = curr_sum / 10;

            temp_2 = temp_2->next;
        }

        if (carry == 1)
        {
            ListNode *new_node = new ListNode(1);
            insert->next = new_node;
            insert = new_node;
        }
        return dummy->next;
    }
};