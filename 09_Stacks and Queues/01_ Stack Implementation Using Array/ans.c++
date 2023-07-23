// Question Link : https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack
{
    vector<int> vec;
    int capacity;

public:
    Stack(int capacity)
    {
        // Write your code here.
        this->capacity = capacity;
        return;
    }

    void push(int num)
    {
        // Write your code here.
        if (this->vec.size() != capacity)
        {
            vec.push_back(num);
        }
    }

    int pop()
    {
        // Write your code here.
        if (vec.size() == 0)
        {
            return -1;
        }
        int ans = vec.back();
        vec.pop_back();
        return ans;
    }

    int top()
    {
        // Write your code here.
        if (vec.size() == 0)
        {
            return -1;
        }
        return vec[vec.size() - 1];
    }

    int isEmpty()
    {
        // Write your code here.
        return vec.size() == 0;
    }

    int isFull()
    {
        // Write your code here.
        return vec.size() == capacity;
    }
};
