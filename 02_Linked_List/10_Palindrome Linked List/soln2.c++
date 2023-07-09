// Question Link : https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

// SC : 0(1)
// TC : 0(N)

// This code is inspired by the best solution that striver explained in the solution video of this question.

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

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        // This two conditions are put to accomodate the odd and even length list   middle
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode *head)
    {
        // We need to first find the middle of the linked list
        ListNode *mid = middleNode(head);

        // Now we have to reverse the mid
        ListNode *reversed_mid = reverseList(mid);

        // Now we have to check for the palindrom
        ListNode *temp_1 = head, *temp_2 = reversed_mid;

        while (temp_1 != NULL && temp_2 != NULL)
        {
            if (temp_1->val != temp_2->val)
            {
                return false;
            }
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }

        // In case of the odd length linked list the temp2 will not be null
        // In case of the even length linked list the temp2 will be null
        return true;
    }
};