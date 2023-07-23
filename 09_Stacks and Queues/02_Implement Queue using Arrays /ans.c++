// Question Link : https://www.codingninjas.com/studio/problems/implement-queue-using-arrays_8390825?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

class Queue
{

    vector<int> vec;

public:
    Queue()
    {
        return;
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        vec.push_back(e);
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (vec.size() == 0)
        {
            return -1;
        }
        int ans = vec[0];
        vec.erase(vec.begin());
        return ans;
    }
};