// Question Link : https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void insert(int x, stack<int> &st)
{
    if (st.empty() == true || st.top() <= x)
    {
        st.push(x);
        return;
    }
    else
    {
        int temp = st.top();
        st.pop();

        insert(x, st);

        st.push(temp);
        return;
    }
}

void sortStack(stack<int> &st)
{
    if (st.empty() == true)
    {
        return;
    }
    int temp = st.top();
    st.pop();

    sortStack(st);

    insert(temp, st);
    return;
}