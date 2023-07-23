// Question Link : https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

// Our challenge is to do this job using only one stack

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        if (st.size() == 1)
        {
            int ans = st.top();
            st.pop();
            return ans;
        }
        int temp = st.top();
        st.pop();

        int ans = pop();

        st.push(temp);
        return ans;
    }

    int peek()
    {
        if (st.size() == 1)
        {
            int ans = st.top();
            return ans;
        }
        int temp = st.top();
        st.pop();

        int ans = peek();

        st.push(temp);
        return ans;
    }

    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */