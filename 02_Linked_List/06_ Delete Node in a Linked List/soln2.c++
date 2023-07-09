// Question Link : https://leetcode.com/problems/delete-node-in-a-linked-list/description/

// I got this solution from the editorial section of this problem in leetcode.

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

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Since we know input node is not last node, so nextNode will not be null
        ListNode *nextNode = node->next;
        // Step 2
        node->val = nextNode->val;
        // Step 3
        node->next = nextNode->next;
        nextNode->next = nullptr;
        delete(nextNode);
    }
};