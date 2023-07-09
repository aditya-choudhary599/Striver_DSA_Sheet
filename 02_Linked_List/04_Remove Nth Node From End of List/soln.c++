// Question Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include<bits/stdc++.h>
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

    int length(ListNode *head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+length(head->next);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=length(head);
        int pos_to_remove=size-n+1;
        if(pos_to_remove==1)
        {
            return head->next;
        }
        ListNode *temp=head;
        for(int i=1;i<pos_to_remove-1;i+=1)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};