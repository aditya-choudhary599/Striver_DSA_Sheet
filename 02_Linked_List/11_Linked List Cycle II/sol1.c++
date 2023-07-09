// Question Link : https://leetcode.com/problems/linked-list-cycle-ii/description/

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
        unordered_map<ListNode *, int> mp;
        while (head != NULL)
        {
            mp[head] += 1;
            if (mp[head] > 1)
            {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};