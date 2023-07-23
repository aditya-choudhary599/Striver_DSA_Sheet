// Question Link : https://www.codingninjas.com/studio/problems/next-greater-element_670312?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> st;
    int i = n - 1;
    while (i >= 0)
    {
        if (st.empty() == true)
        {
            ans.push_back(-1);
            st.push(arr[i]);
            i -= 1;
            continue;
        }
        if (st.top() > arr[i])
        {
            ans.push_back(st.top());
            st.push(arr[i]);
            i -= 1;
        }
        else
        {
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}