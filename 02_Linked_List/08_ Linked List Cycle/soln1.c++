// Question Link : https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> mp;
        while (head != NULL)
        {
            mp[head] += 1;
            if (mp[head] > 1)
            {
                return true;
            }
            head = head->next;
        }
        // This means we escape the ll and thier is no cycle here
        return false;
    }
};