// Question Link : https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        return;
    }

    void pop()
    {
        st.pop();
        return;
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        vector<int> helper;
        int mini = INT_MAX;
        while (st.empty() != true)
        {
            mini = min(mini, st.top());
            helper.push_back(st.top());
            st.pop();
        }
        int n = helper.size();
        for (int i = n - 1; i >= 0; i -= 1)
        {
            st.push(helper[i]);
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */