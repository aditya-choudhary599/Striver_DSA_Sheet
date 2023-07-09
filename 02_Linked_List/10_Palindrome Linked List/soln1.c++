// Question Link : https://leetcode.com/problems/palindrome-linked-list/description/

// SC : 0(N)
// TC : 0(N)

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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *temp = NULL, *helper = head;
        while (helper != NULL)
        {
            ListNode *new_node = new ListNode(helper->val);
            new_node->next = temp;
            temp = new_node;

            helper = helper->next;
        }
        while (head != NULL && temp != NULL)
        {
            if (head->val != temp->val)
            {
                return false;
            }
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};