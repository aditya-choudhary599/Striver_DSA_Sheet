// Question Link : https://www.codingninjas.com/studio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2

#include <bits/stdc++.h>
using namespace std;

//  Definition for linked list.
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *small_ans = flattenLinkedList(head->next);

    Node *dummy = new Node();
    Node *insert = dummy;
    Node *temp_1 = small_ans, *temp_2 = head;

    while (temp_1 != NULL && temp_2 != NULL)
    {
        if (temp_1->data <= temp_2->data)
        {
            Node *new_node = new Node(temp_1->data);
            insert->child = new_node;
            insert = new_node;
            temp_1 = temp_1->child;
        }
        else
        {
            Node *new_node = new Node(temp_2->data);
            insert->child = new_node;
            insert = new_node;
            temp_2 = temp_2->child;
        }
    }

    while (temp_1 != NULL)
    {
        Node *new_node = new Node(temp_1->data);
        insert->child = new_node;
        insert = new_node;
        temp_1 = temp_1->child;
    }

    while (temp_2 != NULL)
    {
        Node *new_node = new Node(temp_2->data);
        insert->child = new_node;
        insert = new_node;
        temp_2 = temp_2->child;
    }

    return dummy->child;
}
