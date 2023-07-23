// Question Link : https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &st)
{
    vector<int> ans;
    while (st.empty() != true)
    {
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(), ans.end());
    for (auto num : ans)
    {
        st.push(num);
    }
    return;
}