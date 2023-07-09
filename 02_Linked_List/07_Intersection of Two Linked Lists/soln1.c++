// Question Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *head_1, ListNode *head_2)
    {
        unordered_map<ListNode *, bool> mp;
        ListNode *temp_1 = head_1, *temp_2 = head_2;

        while (temp_1 != NULL && temp_2 != NULL)
        {
            if (temp_1 == temp_2)
            {
                return temp_1;
            }
            if (mp.find(temp_1) != mp.end())
            {
                return temp_1;
            }
            if (mp.find(temp_2) != mp.end())
            {
                return temp_2;
            }

            mp[temp_1] = true;
            mp[temp_2] = true;
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }

        while (temp_1 != NULL)
        {
            // No need to put this into the map
            if (mp.find(temp_1) != mp.end())
            {
                return temp_1;
            }
            temp_1 = temp_1->next;
        }

        while (temp_2 != NULL)
        {
            // No need to put this into the map
            if (mp.find(temp_2) != mp.end())
            {
                return temp_2;
            }
            temp_2 = temp_2->next;
        }

        return NULL;
    }
};