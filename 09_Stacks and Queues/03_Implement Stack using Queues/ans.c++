// Question Link : https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

// Here challenege is to do the question using the single queue only

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
        return;
    }

    void push(int x)
    {
        q.push(x);
        return;
    }

    void reverse_q()
    {
        if (q.size() == 0)
        {
            return;
        }
        int temp = q.front();
        q.pop();

        reverse_q();

        q.push(temp);
        return;
    }

    int helper_pop()
    {
        if (q.size() == 1)
        {
            int ans = q.front();
            q.pop();
            return ans;
        }
        int temp = q.front();
        q.pop();

        int ans = helper_pop();

        q.push(temp);
        return ans;
    }

    int pop()
    {
        if (q.size() != 0)
        {
            int ans = helper_pop();
            reverse_q();
            return ans;
        }
        return -1;
    }

    int top()
    {
        if (q.size() != 0)
        {
            int ans = pop();
            q.push(ans);
            return ans;
        }
        return -1;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */